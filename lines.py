import os
# 15140
def count_lines_in_cpp_files(directory):
    total_lines = 0

    # Walk through the directory
    for root, dirs, files in os.walk(directory):
        # Exclude .git directory
        if '.git' in dirs:
            dirs.remove('.git')
        for dir in dirs:
            if "build" in dir:
                dirs.remove(dir)
        
        for file in files:
            if file.endswith('.cpp'):
                file_path = os.path.join(root, file)
                print(f"file: {file_path}")
                try:
                    with open(file_path, 'r', encoding='utf-8') as f:
                        lines = f.readlines()
                        total_lines += len(lines)
                except Exception as e:
                    print(f"Error reading file {file_path}: {e}")

    return total_lines

# Example usage
project_directory = '/mnt/5EE9F38E0E9F2DC9/ispa-parser'
total_lines = count_lines_in_cpp_files(project_directory)
print(f"Total lines in all .cpp files: {total_lines}")
