import sys
import re
import os

def find_includes(filename):
    include_pattern = re.compile(r'^\s*#\s*include\s*([<"][^>"]+[>"])')
    includes = []

    try:
        with open(filename, 'r', encoding='utf-8') as f:
            for line in f:
                match = include_pattern.match(line)
                if match:
                    includes.append(match.group(1))
    except (FileNotFoundError, UnicodeDecodeError):
        # Could be a binary or unreadable file, ignore
        return []

    return includes

def scan_directory(directory):
    for root, _, files in os.walk(directory):
        for file in files:
            # Optional: filter typical C/C++ source files
            if file.endswith(('.c', '.cpp', '.h', '.hpp')):
                full_path = os.path.join(root, file)
                includes = find_includes(full_path)
                if includes:
                    print(f"#include directives in {full_path}:")
                    for inc in includes:
                        print(f"  {inc}")
                    print()  # blank line between files

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} <directory>")
        sys.exit(1)

    directory = sys.argv[1]
    if not os.path.isdir(directory):
        print(f"Error: '{directory}' is not a directory.")
        sys.exit(1)

    scan_directory(directory)
