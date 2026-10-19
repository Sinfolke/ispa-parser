import os

def count_lines_in_cpp_files(directory):
    total_lines = 0

    # Directories to completely skip during traversal
    excluded_dirs = {
        '.git',
        'cmake-build-release',
        'cmake-build-debug',
        'cmake-build-relwithdebinfo',
        'parser'
    }

    # Walk through the directory tree
    for root, dirs, files in os.walk(directory):
        # Slice assignment (dirs[:]) modifies the list in place so os.walk ignores excluded subtrees
        dirs[:] = [d for d in dirs if d not in excluded_dirs]

        for file in files:
            if file.endswith(('.cpp', '.cppm')):
                file_path = os.path.join(root, file)
                print(f"file: {file_path}")
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        lines = f.readlines()
                        total_lines += len(lines)
                except Exception as e:
                    print(f"Error reading file {file_path}: {e}")

    return total_lines

# Example usage
project_directory = '/mnt/5EE9F38E0E9F2DC9/ispa-parser'
total_lines = count_lines_in_cpp_files(project_directory)
print(f"Total lines in all C++ files: {total_lines}")