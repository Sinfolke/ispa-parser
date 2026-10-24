#!/usr/bin/env python3
"""Regenerate the Python grammar with the Python target."""

import argparse
from pathlib import Path
import subprocess
import tempfile


def main():
    root = Path(__file__).resolve().parent
    options = argparse.ArgumentParser(description=__doc__)
    options.add_argument('generator', type=Path)
    options.add_argument('--output', type=Path, default=root / 'bootstrappedPy')
    args = options.parse_args()
    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='ispa-python-bootstrap-') as temporary:
        generated_root = Path(temporary)
        subprocess.run([
            str(args.generator.resolve()), '-l', 'python', '-a', 'LL',
            '--no-incremental', '--dir', str(root / 'grammar'),
            str(root / 'entry.isc'), '-o', str(generated_root / 'Parser'),
        ], cwd=root, check=True, capture_output=True, text=True)
        for name in ('Parser.py', 'Parser.ispa-export'):
            (output / name).write_bytes((generated_root / name).read_bytes())


if __name__ == '__main__':
    main()
