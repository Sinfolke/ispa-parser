CC     ?= gcc
CFLAGS ?= -O2

all: bench_malloc bench_arena

bench_malloc: main.o parser.tab.o lex.yy.o ast_malloc.o
	$(CC) $(CFLAGS) -o $@ $^

bench_arena: main.o parser.tab.o lex.yy.o ast_arena.o
	$(CC) $(CFLAGS) -o $@ $^

parser.tab.c parser.tab.h: parser.y ast.h
	bison -d -Wall parser.y

lex.yy.c lex.yy.h: lexer.l parser.tab.h
	flex -Cf --header-file=lex.yy.h lexer.l

main.o: main.c lex.yy.h ast.h
parser.tab.o: parser.tab.c ast.h
lex.yy.o: lex.yy.c parser.tab.h
	$(CC) $(CFLAGS) -Wno-unused-function -c lex.yy.c

ast_malloc.o: ast.c ast.h
	$(CC) $(CFLAGS) -c -o $@ ast.c
ast_arena.o: ast.c ast.h
	$(CC) $(CFLAGS) -DARENA -c -o $@ ast.c

clean:
	rm -f bench_malloc bench_arena *.o parser.tab.* lex.yy.* parser.output
