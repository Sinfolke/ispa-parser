#!/usr/bin/env python3
"""Generate large, syntactically equivalent ISPA grammar files by cloning a known-valid rule.

Each cloned top-level rule receives a unique name. Rule bodies and nested rules are
preserved verbatim, so the input exercises the same syntax as the original.
"""
import argparse
from pathlib import Path
import re


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--source', type=Path, required=True, help='A valid standalone ISPA rule .isc file')
    ap.add_argument('--count', type=int, required=True, help='Number of top-level rule copies')
    ap.add_argument('--output', type=Path, required=True)
    ap.add_argument('--prefix', default='benchmark_rule')
    args = ap.parse_args()
    if args.count < 1:
        ap.error('--count must be at least 1')
    original = args.source.read_text(encoding='utf-8')
    # Deliberately change ONLY the first rule identifier, leaving nested names unchanged.
    name = re.search(r'\A(\s*)([A-Za-z_][A-Za-z_0-9]*)(\s*:)', original)
    if not name:
        ap.error('source must begin with a top-level rule declaration: NAME: ... ;')
    prefix = original[:name.start(2)]
    suffix = original[name.end(2):]
    args.output.parent.mkdir(parents=True, exist_ok=True)
    with args.output.open('w', encoding='utf-8', newline='\n') as f:
        for i in range(args.count):
            f.write(prefix)
            f.write(f'{args.prefix}_{i:06d}')
            f.write(suffix)
            if not suffix.endswith('\n'):
                f.write('\n')
            f.write('\n')
    print(f'{args.output}: {args.count} rules, {args.output.stat().st_size:,} bytes')

if __name__ == '__main__':
    main()
