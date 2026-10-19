CC     ?= gcc
CFLAGS ?= -O2

bench: main.o parser.tab.o lex.yy.o
	$(CC) $(CFLAGS) -o $@ $^

parser.tab.c parser.tab.h: parser.y
	bison -d -Wall parser.y

lex.yy.c lex.yy.h: lexer.l parser.tab.h
	flex -Cf --header-file=lex.yy.h lexer.l

main.o: main.c lex.yy.h
parser.tab.o: parser.tab.c
lex.yy.o: lex.yy.c parser.tab.h
	$(CC) $(CFLAGS) -Wno-unused-function -c lex.yy.c

clean:
	rm -f bench *.o parser.tab.* lex.yy.* parser.output
