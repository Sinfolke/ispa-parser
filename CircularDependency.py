import os
import re
import sys
from collections import defaultdict

# Match: "module ModuleName;" or "export module ModuleName;"
module_decl_re = re.compile(r'^\s*(export\s+)?module\s+([a-zA-Z0-9_:.]+)\s*;', re.MULTILINE)

# Match: "import ModuleName;" (only import lines, not module declarations)
import_re = re.compile(r'^\s*import\s+([a-zA-Z0-9_:]+)\s*;', re.MULTILINE)

def collect_modules(root_dir):
    graph = defaultdict(list)
    module_files = {}

    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith(".cppm"):
                path = os.path.join(dirpath, filename)

                with open(path, 'r', encoding='utf-8', errors='ignore') as f:
                    content = f.read()

                    # Extract module name from declaration
                    module_match = module_decl_re.search(content)
                    if not module_match:
                        continue  # Skip if no module declaration

                    module_name = module_match.group(2)  # Group 2 is always the module name
                    module_files[module_name] = path

                    # Extract all imports (module dependencies)
                    imports = import_re.findall(content)

                    # Remove self-imports and duplicates
                    imports = [imp for imp in imports if imp != module_name]
                    graph[module_name].extend(imports)

    return graph, module_files

def print_graph(graph):
    print("📦 Module Import Graph:")
    for mod, deps in graph.items():
        print(f"  {mod} imports: {', '.join(deps) if deps else '(none)'}")
    print()

def find_cycles(graph):
    visited = set()
    all_cycles = []

    def dfs(node, path):
        if node in path:
            cycle = path[path.index(node):] + [node]
            if cycle not in all_cycles:  # Avoid duplicates
                all_cycles.append(cycle)
            return

        if node in visited:
            return

        visited.add(node)
        path.append(node)

        for neighbor in graph.get(node, []):
            dfs(neighbor, path)

        path.pop()

    for start_node in graph:
        dfs(start_node, [])

    return all_cycles

def main():
    if len(sys.argv) < 2:
        print("Usage: python analyze_cppm_imports.py /path/to/source")
        sys.exit(1)

    root = sys.argv[1]
    graph, module_files = collect_modules(root)
    print_graph(graph)

    cycles = find_cycles(graph)
    if cycles:
        print("🚨 Circular dependencies detected:")
        for cycle in cycles:
            print(" -> ".join(cycle))
    else:
        print("✅ No circular dependencies detected.")

if __name__ == "__main__":
    main()
