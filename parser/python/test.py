from bootstrappedPy.Parser import Parser

parser = Parser()
main = parser.parse(open("/mnt/5EE9F38E0E9F2DC9/ispa-parser/parser/python/tests/cls.py").read())
main.printTree()