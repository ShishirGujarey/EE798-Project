all: ast


ast: lex.yy.c parser.tab.c
	g++ -o ast parser.tab.c lex.yy.c -lfl
lex.yy.c: lexer.l
	flex lexer.l

parser.tab.c: parser.y
	bison -d parser.y -Wnone

clean:
	rm lex.yy.c parser.tab.c parser.tab.h *.dot *.pdf ast
