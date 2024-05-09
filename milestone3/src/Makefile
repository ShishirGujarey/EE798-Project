all: ast

ast: lex.yy.c parser.tab.c symbol.cpp tac.cpp x86.cpp
	g++ -o ast parser.tab.c lex.yy.c symbol.cpp tac.cpp x86.cpp -lfl

lex.yy.c: lexer.l
	flex lexer.l

parser.tab.c: parser.y
	bison -d parser.y -Wnone

clean:
	rm lex.yy.c parser.tab.c parser.tab.h *.dot *.pdf *.csv ast
