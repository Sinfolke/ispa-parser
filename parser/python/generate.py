#!/usr/bin/env python3
"""Regenerate the Python bootstrap while preserving its public flat type names."""
import argparse
from pathlib import Path
import subprocess
import tempfile


def main():
    root = Path(__file__).resolve().parent
    options = argparse.ArgumentParser(description=__doc__)
    options.add_argument("generator", type=Path)
    options.add_argument("--output", type=Path, default=root / "bootstrapped")
    args = options.parse_args()
    generator = args.generator.resolve()
    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=True)
    manifest = (root / "ispa-compat.ispa-export").read_bytes()
    sources = [root / "entry.isc", *sorted((root / "grammar").rglob("*.isc"))]
    # The bootstrap API predates module-qualified types. These modules have
    # unique declarations; flatten only their module/import directives.
    grammar = "\n\n".join(
        "\n".join(line for line in source.read_text().splitlines()
                  if not line.startswith(("module ", "import ")))
        for source in sources)
    with tempfile.TemporaryDirectory(prefix="ispa-python-") as temporary:
        source = Path(temporary) / "python.isc"
        source.write_text(grammar)
        subprocess.run([str(generator), str(source), "-l", "cpp", "-a", "LL",
                        "--no-incremental", "-o", str(output / "PyRawParser")],
                       cwd=temporary, check=True)
    header = output / "PyRawParser.h"
    with header.open("a") as stream:
        stream.write("\n" + (root / "exports.hpp").read_text())
    # These entry points use the custom Python lexer and must retain their
    # hand-written external bindings rather than generated raw-lexer bindings.
    (output / "PyRawParser.ispa-export").write_bytes(manifest)


if __name__ == "__main__":
    main()
