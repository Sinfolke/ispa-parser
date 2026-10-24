from pathlib import Path
from bootstrap_runtime import custom_failure, make_lexer
import sys

root = Path(__file__).resolve().parent
sys.path.insert(0, str(root.parent / 'stdlibs' / 'target'))
generated = root / 'bootstrappedPy' / 'Parser.py'

from bootstrappedPy.Parser import Parser
from ispa_std import format_ast


parser = Parser()
main = parser.parse((root / 'tests' / 'cls.py').read_text())
assert len(main.data().value.data().value) == 1
assert not parser.errors
print(f'Python bootstrap parsed cls.py')
with open("result.txt", "w") as f:
        f.write(format_ast(main, indent=2))
