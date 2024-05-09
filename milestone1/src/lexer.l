%option yylineno
%{  
  
	#include<bits/stdc++.h>
    using namespace std;
    #include "ast1.h"
	#include "parser.tab.h"
	
    stack<int> st;
	
%}

/*KEYWORD False|await|else|import|pass|None|break|except|in|raise|True|class|finally|is|return|and|continue|for|lambda|try|as|def|from|nonlocal|while|assert|del|global|not|with|async|elif|if|or|yield*/
/*OPERATOR and|or|not|"+"|"-"|"*"|"/"|"//"|"%"|"**"|"=="|"&"|"<<"|">>"|">="|"<="|"!="|">"|"<"|"|"|"^"|"~"|"="|"+="|"-="|"*="|"/="|"//="|"%="|"**="|"&="|"|="|"^="|"<<="|">>="*/

/*TYPE int|bool|list|float*/

DIGIT [0-9]
HEXDIGIT {DIGIT}|[A-Fa-f]
DIGIT_PART {DIGIT}(["_"]?{DIGIT})*
INTEGER {DECINTEGER}|{BIN_INT}|{OCT_INT}|{HEX_INT}
DECINTEGER [1-9](["_"]?{DIGIT})*|"0"+("_"|"0")*
BIN_INT "0"("B"|"b")(["_"]?[0-1])+
OCT_INT "0"("O"|"o")(["_"]?[0-7])+
HEX_INT "0"("x"|"X")(["_"]?{HEXDIGIT})+

FLOATING_POINT {POINT_FLOAT}|{EXP_FLOAT}
POINT_FLOAT {DIGIT_PART}"."{DIGIT_PART}
EXP_FLOAT ({DIGIT_PART}|{POINT_FLOAT})("E"|"e")["+"|"-"]{DIGIT_PART}

LETTER [A-Za-z]
IDENTIFIER ({LETTER}|"_")({LETTER}|{DIGIT}|"_")*

DELIMITER "@"|";"|":"|","|"."|"["|"]"|"{"|"}"|"("|")"
WS              [ \t\f\n\r]|\r\n 
 /* \r ignored in linux */

stringescapeseq      \\[^\n]*
longstringchar       [^\\]+
shortstringchar      [^(\\)(\n)\"]+
longstringitem       {longstringchar}|{stringescapeseq}
shortstringitem      {shortstringchar}|{stringescapeseq}
longstring           [\'][\'][\']{longstringitem}*[\'][\'][\']|[\"][\"][\"]{longstringitem}*[\"][\"][\"]
shortstring          [\']{shortstringitem}*[\']|[\"]{shortstringitem}*[\"]
stringprefix    	 "r"|"u"|"R"|"U" 
stringliteral   	 ({stringprefix})?({shortstring}|{longstring})

bytesescapeseq       \\[^\n]*
longbyteschar        [^\\]+ 
shortbyteschar       [^(\\)(\n)\"]+ 
longbytesitem        {longbyteschar}|{bytesescapeseq}
shortbytesitem       {shortbyteschar}|{bytesescapeseq}
longbytes            [\'][\'][\']{longbytesitem}*[\'][\'][\']|[\"][\"][\"]{longbytesitem}*[\"][\"][\"]
shortbytes           [\']{shortbytesitem}*[\']|[\"]{shortbytesitem}*[\"]
bytesprefix          "b"|"B"|"br"|"Br"|"bR"|"BR"|"rb"|"rB"|"Rb"|"RB"
bytesliteral         ({bytesprefix})({shortbytes}|{longbytes})


%%

%{
  /*
   * These lines go at the top of the lexing function.  We only want to
   * initialize the indentation level stack once by pushing a 0 onto it (the
   * indentation stack should never be empty, except immediately after it is
   * created).
   */
  if (st.empty()) {
    st.push(0);
  }

  /*
   * We also want to initialize a parser state to be sent to the parser on
   * each push parse call.
   */
  yypstate* pstate = yypstate_new();

  YYSTYPE yylval;
//   YYLTYPE loc;

  /*
   * This macro invokes the push parser for a new token.
   */
  #define PUSH_TOKEN(category, lexeme) do {                         \
    yylval.str = lexeme ? new std::string(lexeme) : NULL;              \
                     \
    int status = yypush_parse(pstate, category, &yylval);   \
    if (status != YYPUSH_MORE) {                               \
      yypstate_delete(pstate);                                 \
      return status;                                           \
    }                                                          \
  } while (0)
%}

       
^[ \t]*\r?\n {}
^[ \t]*#.*\r?\n {}
#.*$ {}

 ^([ ][ ])* {
    
    if (st.top() < yyleng) {
                st.push(yyleng);
                PUSH_TOKEN(INDENT, NULL);
              }
    else {
               
                while (!st.empty() && st.top() != yyleng) {
                  st.pop();
                  PUSH_TOKEN(DEDENT, NULL);
                }

                if (st.empty()) {
                  std::cerr << "Error: Incorrect indentation on line "
                    << yylineno << std::endl;
                  return 1;
                }
              }
}
^[^ \t\n]+  {
              
              while(st.top() != 0) {
                st.pop();
                PUSH_TOKEN(DEDENT, NULL);
              }
              REJECT;
            }

"->" {PUSH_TOKEN(R_ARR,NULL);}
{stringliteral} {yylval.str = new std::string(yytext, yyleng);
					PUSH_TOKEN(STR_LIT,yytext);
				} 
{bytesliteral}	{yylval.str = new std::string(yytext, yyleng);
    PUSH_TOKEN(BYT_LIT,yytext);
}




"range" {
	yylval.str = new std::string(yytext, yyleng); PUSH_TOKEN(RANGE,NULL);
}
"len" {
	yylval.str = new std::string(yytext, yyleng); PUSH_TOKEN(LEN,NULL);
}

"int" {
	yylval.str = new std::string(yytext, yyleng); PUSH_TOKEN(INT,yytext);
}

"float" {
	yylval.str = new std::string(yytext, yyleng); PUSH_TOKEN(FLOAT,yytext);
}

"list" {
	yylval.str = new std::string(yytext, yyleng); PUSH_TOKEN(LIST,NULL);
}

"str" {
	yylval.str = new std::string(yytext, yyleng); PUSH_TOKEN(STR,NULL);
}
"bool" {
	yylval.str = new std::string(yytext, yyleng); PUSH_TOKEN(BOOL,NULL);
}
{INTEGER} { yylval.str = new std::string(yytext, yyleng);PUSH_TOKEN(NUMBER,yytext); }
{FLOATING_POINT} {yylval.str = new std::string(yytext, yyleng);PUSH_TOKEN(FLOATING_POINT,yytext);}

{HEX_INT} { yylval.str = new std::string(yytext, yyleng);PUSH_TOKEN(HEX,yytext); }
[ \t]       { /* Ignore spaces that haven't been handled above. */ }
\r?\n     { PUSH_TOKEN(((yylval.token=NEWLINE)),NULL); }

"False"   { PUSH_TOKEN(FALSE,NULL); }
"await"   { PUSH_TOKEN(AWAIT,NULL); }
"else"    { PUSH_TOKEN(ELSE,NULL); }
"import"  { PUSH_TOKEN(IMPORT,NULL); }
"pass"    { PUSH_TOKEN(PASS,NULL); }
"None"    { PUSH_TOKEN(NONE,NULL); }
"break"   { PUSH_TOKEN(BREAK,NULL); }
"except"  { PUSH_TOKEN(EXCEPT,NULL); }
"in"      { PUSH_TOKEN(IN,NULL); }
"raise"   { PUSH_TOKEN(RAISE,NULL); }
"True"    { PUSH_TOKEN(TRUE,NULL); }
"class"   { PUSH_TOKEN(CLASS,NULL); }
"finally" { PUSH_TOKEN(FINALLY,NULL); }
"is"      { PUSH_TOKEN(IS,NULL); }
"return"  { PUSH_TOKEN(RETURN,NULL); }
"and"     { PUSH_TOKEN(AND,NULL); }
"continue" { PUSH_TOKEN(CONTINUE,NULL); }
"for"     { PUSH_TOKEN(FOR,NULL); }
"lambda"  { PUSH_TOKEN(LAMBDA,NULL); }
"try"     { PUSH_TOKEN(TRY,NULL); }
"as"      { PUSH_TOKEN(AS,NULL); }
"def"     { PUSH_TOKEN(DEF,NULL); }
"from"    { PUSH_TOKEN(FROM,NULL); }
"nonlocal" { PUSH_TOKEN(NONLOCAL,NULL); }
"while"   { PUSH_TOKEN(WHILE,NULL); }
"assert"  { PUSH_TOKEN(ASSERT,NULL); }
"del"     { PUSH_TOKEN(DEL,NULL); }
"global"  { PUSH_TOKEN(GLOBAL,NULL); }
"not"     { PUSH_TOKEN(NOT,NULL); }
"with"    { PUSH_TOKEN(WITH,NULL); }
"async"   { PUSH_TOKEN(ASYNC,NULL); }
"elif"    { PUSH_TOKEN(ELIF,NULL); }
"if"      { PUSH_TOKEN(IF,NULL); }
"or"      { PUSH_TOKEN(OR,NULL); }
"yield"   { PUSH_TOKEN(YIELD,NULL); }

{IDENTIFIER} {
	yylval.str = new std::string(yytext, yyleng);
	PUSH_TOKEN(IDENTIFIER,yytext);
}

"="   { PUSH_TOKEN(((yylval.token=EQUALS)),NULL); }
"+"   { PUSH_TOKEN(((yylval.token=PLUS)),NULL); }
"-"   { PUSH_TOKEN(((yylval.token=MINUS)),NULL); }
"*"   { PUSH_TOKEN(((yylval.token=TIMES)),NULL); }
"/"   { PUSH_TOKEN(((yylval.token=DIVIDEDBY)),NULL); }
"//"  { PUSH_TOKEN(((yylval.token=MOD)),NULL);}
"+="   { PUSH_TOKEN(((yylval.token=AUGPLUS)),NULL); }
"-="   { PUSH_TOKEN(((yylval.token=AUGMINUS)),NULL); }
"*="   { PUSH_TOKEN(((yylval.token=AUGTIMES)),NULL); }
"/="   { PUSH_TOKEN(((yylval.token=AUGDIVIDEDBY)),NULL); }
"//="  { PUSH_TOKEN(((yylval.token=AUGMOD)),NULL);}
"%"  { PUSH_TOKEN(((yylval.token=MODULO)),NULL);}
"%="  { PUSH_TOKEN(((yylval.token=AUGMODULO)),NULL);}
"**"  { PUSH_TOKEN(((yylval.token=POW)),NULL);}
"**="  { PUSH_TOKEN(((yylval.token=AUGPOW)),NULL);}

"=="  { PUSH_TOKEN(((yylval.token=EQ)),NULL); }
"!="  { PUSH_TOKEN(((yylval.token=NEQ)),NULL); }
">"   { PUSH_TOKEN(((yylval.token=GT)),NULL); }
">="  { PUSH_TOKEN(((yylval.token=GTE)),NULL); }
"<"   { PUSH_TOKEN(((yylval.token=LT)),NULL); }
"<="  { PUSH_TOKEN(((yylval.token=LTE)),NULL); }
"("   { PUSH_TOKEN(((yylval.token=LPAREN)),NULL); }
")"   { PUSH_TOKEN(((yylval.token=RPAREN)),NULL); }
","   { PUSH_TOKEN(((yylval.token=COMMA)),NULL); }
":"   { PUSH_TOKEN(((yylval.token=COLON)),NULL); }
";"   { PUSH_TOKEN(((yylval.token=SEMICOLON)),NULL); }
"&"  { PUSH_TOKEN(((yylval.token=BIT_AND)),NULL);}
"|" { PUSH_TOKEN(((yylval.token=BIT_OR)),NULL);}
"^" { PUSH_TOKEN(((yylval.token=BIT_XOR)),NULL);}
"~" {PUSH_TOKEN(((yylval.token=BIT_NOT)),NULL);}
">>" { PUSH_TOKEN(((yylval.token=BIT_RSHIFT)),NULL);}
"<<" { PUSH_TOKEN(((yylval.token=BIT_LSHIFT)),NULL);}
"&="  { PUSH_TOKEN(((yylval.token=AUGBIT_AND)),NULL);}
"|=" { PUSH_TOKEN(((yylval.token=AUGBIT_OR)),NULL);}
"^=" { PUSH_TOKEN(((yylval.token=AUGBIT_XOR)),NULL);}
">>=" { PUSH_TOKEN(((yylval.token=AUGBIT_RSHIFT)),NULL);}
"<<=" { PUSH_TOKEN(((yylval.token=AUGBIT_LSHIFT)),NULL);}
"." {PUSH_TOKEN(((yylval.token=DOT)),NULL);}
"[" {PUSH_TOKEN(((yylval.token=LLIST)),NULL);}
"]" {PUSH_TOKEN(((yylval.token=RLIST)),NULL);}

<<EOF>> { 
    while(st.top() != 0) {
                st.pop();
                PUSH_TOKEN(DEDENT, NULL);
    }
    int status = yypush_parse(pstate, 0, NULL);
    yypstate_delete(pstate);
    return status;
            //   return ENDMARKER; 
}

{WS}   {}


.     {
        std::cerr << "Unrecognized token on line " << yylineno << ": " << yytext << std::endl;
        return 1;
      }
%%


int yywrap() {
    return 1;
}
