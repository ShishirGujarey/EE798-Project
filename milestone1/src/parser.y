%{
    #include<bits/stdc++.h>
    using namespace std;
    #include "ast1.h"
    extern int yylex();
    #define YYERROR_VERBOSE 1
    // extern int yyparse();
    extern FILE *yyin;
     extern int yylineno;
     extern int yydebug;
    
    extern FILE *yyout;

    FILE *program;
    string input_file = "../tests/test1.py";
    string output_file = "graph.dot"; 
    void yyerror(const char *s) {
 
    fprintf(stderr, "Error at line %d: %s\n",yylineno, s);}
    Node *root = NULL;

Node *createNode(string label, string value, vector <Node *> children) {

    Node *temp = new Node();
    temp->value = value;
    temp->children = children;
    temp->label = label;
    
    return temp;
}
   
%}
%define parse.error verbose
%union {
  std::string* str;
  int token;
  Node * node;
}

// %locations
//%define api.pure full
//%define api.push-pull push
%define api.pure full
%define api.push-pull push
//%define parse.error verbose
//%define parse.error verbose

%token <str> IDENTIFIER DELIMITER  FLOATING_POINT NUMBER TRUE FALSE TYPE STR_LIT BYT_LIT STR LIST FLOAT BOOL
%token <token> EQUALS PLUS MINUS TIMES DIVIDEDBY NEWLINE MOD MODULO AUGPLUS AUGMINUS AUGTIMES AUGDIVIDEDBY AUGMOD AUGMODULO POW AUGPOW
%token <token> BIT_AND BIT_OR BIT_XOR BIT_NOT BIT_RSHIFT BIT_LSHIFT AUGBIT_AND AUGBIT_OR AUGBIT_XOR AUGBIT_NOT AUGBIT_RSHIFT AUGBIT_LSHIFT
%token <token> LPAREN RPAREN COMMA DOT COLON SEMICOLON LLIST RLIST R_ARR
%token <token> EQ NEQ GT GTE LT LTE HEX INT AWAIT LEN 
%token <token> AND BREAK DEF ELIF ELSE FOR IF ENDMARKER RANGE
%token <token> NOT OR RETURN WHILE INDENT DEDENT NONE IS IN CONTINUE ASSERT NONLOCAL GLOBAL CLASS ASYNC 
%token <token> IMPORT PASS EXCEPT RAISE FINALLY LAMBDA TRY AS FROM DEL WITH YIELD


%type<node> rarr_test_maybe
%type<node> file simple_stmt simple_stmts single_inputs single_input func_type_input compound_stmt async_funcdef funcdef parameters 
%type<node> func_body_suite arguments argument comm_arg tfpdef equals_test_maybe kwargs kwonly_kwargs comma_kwargs_maybe args_kwonly_kwargs 
%type<node> typedargslist_no_posonly poskeyword_args_kwonly_kwargs comma_argskwonlykwargs typedargslist comma_typedargs_maybe
%type<node> colon_test_maybe stmt small_stmt1 small_stmt type1 type expr_stmt expr_list eq_test annassign annassign_a
%type<node> testlist_star_expr test_star comm_test_star augassign flow_stmt break_stmt continue_stmt return_stmt global_stmt 
%type<node> comm_name nonlocal_stmt assert_stmt comma_test_maybe  async_stmt if_stmt while_stmt for_stmt
%type<node> else_colon_suite_maybe  elif_namedexprtest_colon_suite suite stmt_morethanone test if_ortest_else_test_maybe
%type<node> or_test or_andtest and_test and_nottest not_test comparison comp_op_expr comp_op star_expr expr bitor_xorexpr
%type<node> xor_expr bitxor_andexpr and_expr bitand_shiftexpr shift_expr lrshift_arithexpr lorrshift_arithexpr lshift_or_rshift
%type<node> arith_expr plusorminus_term plus_or_minus term timedivmod_factor timedivmod factor plusminusnot power pow_factor_maybe
%type<node> atom_expr trailer_ atom string_pl testlist_comp testlist_comp_a comma_testorstar test_or_starexpr trailer subscriptlist
%type<node> comma_subscript subscript sliceop_maybe sliceop exprlist expr_str comm_exstr testlist comm_test dictorsetmaker
%type<node> compfor_comtestpowcom compfor_comteststarcom testcoltest_powexpr comma_testpow classdef l_arglist_r_maybe arglist
%type<node> comp_iter sync_comp_for comp_for comp_if encoding_decl  nls typelist comma_typel_maybe type_l 
%type<node> comma_pow_test_maybe comma_maybe args argument_a func_type comm_arg_a
%start file

%%
file: single_inputs{Node * temp=createNode("EOF","<EOF>",{}); root =createNode("file","",{$1,temp});}  
|     func_type_input {Node * temp=createNode("EOF","<EOF>",{}); root =createNode("file","",{$1,temp});}
;
single_inputs : single_inputs single_input { $$=$1;
$$->children.push_back($2);
}
|               single_input {$$=createNode("single_inputs","",{$1});}
single_input: NEWLINE {$$=createNode("Newline","nl",{});}
|             simple_stmt {$$=$1;}
|             compound_stmt{$$=$1;}
|             compound_stmt NEWLINE{Node *n1=createNode("Newline","nl",{}); $$=createNode("single_input","",{$1,n1});}
;
async_funcdef: ASYNC funcdef {Node* n1=createNode("Keyword","async",{});$$=createNode("Async_func","",{n1,$1});}
funcdef: DEF IDENTIFIER parameters rarr_test_maybe COLON func_body_suite{Node* n2= createNode("Keyword","def",{});Node* n3= createNode("Identifier",*$2,{});Node* n4= createNode("Delimiter",":",{});$$=createNode("Func","",{n2,n3,$3,$4,n4,$6});}
rarr_test_maybe: R_ARR type{Node * n5= createNode("Delimiter","->",{});$$=createNode("rarr_maybe","",{n5,$2});} | {$$=createNode("rarr_test_maybe","",{});}
parameters: LPAREN typedargslist RPAREN {Node *n6= createNode("Delimiter","(",{});Node *n7= createNode("Delimiter",")",{});$$=createNode("params","",{n6,$2,n7});}
;
arguments: argument_a comm_arg_a {$$=createNode("args","",{$1,$2});}
argument_a: tfpdef equals_test_maybe{$$=createNode("arg","",{$1,$2});}
comm_arg_a: comm_arg_a COMMA argument_a {$$=$1; Node *n1=createNode("Delimiter", ",", {}); $$->children.push_back(n1); $$->children.push_back($3);}| {$$=createNode("comm_arg_a", "", {});}

equals_test_maybe: EQUALS test {Node *n8=createNode("Assign","=",{});$$=createNode("args","",{n8,$2});} | {$$=createNode("equals_test_maybe","",{});} 
kwargs: POW tfpdef comma_maybe {Node *n9=createNode("Operator","Power(**)",{});  $$=createNode("args","",{n9,$2,$3});} 
comma_maybe: COMMA {Node *n10=createNode("COMMA",",",{});} | {$$=createNode("comma_maybe","",{});} 
args:TIMES tfpdef {   Node *n11 = createNode("Operator","Times(*)",{});
                        $$=createNode("args","",{n11,$2});}
    | TIMES {Node *n11 = createNode("Operator","Times(*)",{});
            $$ = createNode("args","",{n11});
                    };
kwonly_kwargs:comm_arg_a comma_kwargs_maybe { $$=createNode("kwarg","",{$1,$2});}
comma_kwargs_maybe: COMMA kwargs{   Node *n12 = createNode("Delimiter",",",{});
                                        $$ = createNode("kwargs","",{n12,$2});
                                    } 
                    | COMMA{$$ = createNode("Delimiter",",",{});}
                    | {$$=createNode("comma_kwargs_maybe","",{});} 
args_kwonly_kwargs: args kwonly_kwargs { $$=createNode("args_kw","nkw",{$1,$2});}
                    |kwargs { $$=$1;};
poskeyword_args_kwonly_kwargs: arguments comma_argskwonlykwargs { $$=createNode("poskeyword_args_kwonly_kwargs","",{$1,$2});}
comma_argskwonlykwargs:  {$$=createNode("comma_argskwonlykwargs","",{});} 
|                       COMMA args_kwonly_kwargs {   Node *n11 = createNode("Delimiter",",",{});
                                                         $$=createNode("comma_argskwonlykwargs","",{n11,$2});
                                                        }
|                       COMMA {$$ = createNode("Delimiter",",",{});} 
                       
typedargslist_no_posonly: poskeyword_args_kwonly_kwargs  { $$=$1;} 
|                         args_kwonly_kwargs { $$=$1;}
typedargslist: {$$=createNode("typedargslist","",{});}
|             arguments COMMA DIVIDEDBY comma_typedargs_maybe {Node* n3= createNode("div_by","/",{}); Node* n2= createNode("Delimiter",",",{});$$=createNode("typedargslist","",{$1,n2,n3,$4});} 
|               typedargslist_no_posonly {  $$=$1;}
comma_typedargs_maybe:{$$=createNode("comma_typedargs_maybe","",{});} 
|                       COMMA typedargslist_no_posonly {   Node *n11 = createNode("COMMA",",",{});
                                                         $$=createNode("comma_typedargs_yes","",{n11,$2});
                                                        }
|                       COMMA {$$ = createNode("COMMA",",",{});} 
tfpdef: IDENTIFIER colon_test_maybe {Node *n11 = createNode("IDENTIFIER",*$1,{});
                                                         $$=createNode("tfpdef","",{n11,$2});}
colon_test_maybe: COLON  type {Node *n11 = createNode("Delimiter",":",{});
                                                         $$=createNode("colon_test_yes","",{n11,$2});}
                | {$$=createNode("colon_test_maybe","",{});}
simple_stmts : simple_stmts simple_stmt {$$ = $1;$$->children.push_back($2);}
|              simple_stmt {$$ = createNode("simple_stmts", "", {})}
stmt: simple_stmt{ $$ = $1;} 
|     compound_stmt{$$ = $1;}
simple_stmt: small_stmt small_stmt1 SEMICOLON NEWLINE  { Node* n3= createNode("Delimiter",";",{}); Node* n4= createNode("newline","nl",{});$$=createNode("simple_stmt","",{$1,$2,n3,n4});} 
|            small_stmt small_stmt1 NEWLINE {  Node* n3= createNode("newline","nl",{});$$=createNode("simple_stmt","",{$1,$2,n3});} 
|            small_stmt small_stmt1 SEMICOLON { { Node* n3= createNode("Delimiter",";",{}); $$=createNode("simple_stmt","",{$1,$2,n3});} }
|            small_stmt small_stmt1 { $$=createNode("simple_stmt","",{$1,$2});} 

small_stmt1: small_stmt1 SEMICOLON small_stmt { $$=$1; Node* n1= createNode("Delimiter",";",{}); $$->children.push_back(n1); $$->children.push_back($3);}
| {$$=createNode("small_stmt1", "", {});}

small_stmt: expr_stmt {$$ = $1;}
    //| pass_stmt
    | flow_stmt {$$ = $1;}
    //| import_stmt 
    | global_stmt {$$ = $1;}
    | nonlocal_stmt {$$ = $1;}
    | assert_stmt {$$ = $1;} 


type1: INT {$$=createNode("Keyword","int",{});}
    | FLOAT {$$=createNode("Keyword","float",{});}
    | STR {$$=createNode("Keyword","str",{});}
    | BOOL {$$=createNode("Keyword","bool",{});}
    | NONE {$$=createNode("Keyword","None",{});}  
    | IDENTIFIER {$$=createNode("Identifier",*$1,{});}
type: type1 {$$=$1;}
    | LIST LLIST type1 RLIST {
        Node *lst=createNode("Keyword","list",{});
        Node * ll=createNode("Delimiter","[",{});
        Node* rl=createNode("Delimiter","]",{});
        $$=createNode("type","t",{lst,ll,$3,rl});}
expr_stmt: testlist_star_expr expr_list {$$=createNode("expr_stmt","",{$1,$2});}
expr_list: annassign {$$=$1;}
    | augassign testlist {$$=createNode("expr_list","",{$1,$2});}
    | EQUALS testlist_star_expr eq_test{Node * eq=createNode("Equals","=",{});$$=createNode("expr_list","",{eq,$2,$3});} | {$$=createNode("expr_list","",{});}
eq_test: eq_test EQUALS testlist_star_expr {$$=$1; Node * eq=createNode("Equals","=",{});$$->children.push_back(eq);$$->children.push_back($3);}
        | {$$=createNode("eq_test", "", {});} 
annassign: COLON type annassign_a {Node * cl=createNode("colon",":",{});$$=createNode("Annassign","",{cl,$2,$3});}
annassign_a: EQUALS  testlist_star_expr {Node * eq=createNode("Equals","=",{});$$=createNode("Annassign_a","",{eq,$2});}| {$$=createNode("Annassign_a","",{});}
testlist_star_expr: test_star comm_test_star COMMA {Node * cmma=createNode("comma",",",{});$$=createNode("testlist_star","",{$1,$2,cmma});}
    | test_star comm_test_star {$$=createNode("Testlist_star","",{$1,$2});}
test_star: test {$$ = $1;}
    |star_expr {$$ = $1;}
comm_test_star: comm_test_star COMMA test_star {$$=$1;Node * cmma=createNode("comma",",",{});$$->children.push_back(cmma);$$->children.push_back($3);}
|               {$$=createNode("comm_test_star", "", {});} 

augassign:
     AUGPLUS {$$=createNode("AugAssign","+=",{});}
    | AUGMINUS {$$=createNode("AugAssign","-=",{});}
    | AUGTIMES {$$=createNode("AugAssign","*=",{});}
    | AUGDIVIDEDBY {$$=createNode("AugAssign","/=",{});}
    | AUGMODULO {$$=createNode("AugAssign","%=",{});}
    | AUGBIT_AND {$$=createNode("AugAssign","&=",{});}
    | AUGBIT_OR {$$=createNode("AugAssign","|=",{});}
    | AUGBIT_XOR {$$=createNode("AugAssign","^=",{});}
    | AUGBIT_RSHIFT {$$=createNode("AugAssign","<<=",{});}
    | AUGBIT_LSHIFT {$$=createNode("AugAssign",">>=",{});}
    | AUGPOW {$$=createNode("AugAssign","**=",{});}
    | AUGMOD {$$=createNode("AugAssign","//=",{});}

flow_stmt: break_stmt{$$ = $1;} | continue_stmt{$$ = $1;} | return_stmt{$$ = $1;} 
break_stmt: BREAK {$$=createNode("Keyword","BREAK",{});}
continue_stmt: CONTINUE {$$=createNode("Keyword","CONTINUE",{});}
return_stmt: RETURN testlist_star_expr {Node *n11 = createNode("Keyword","return",{}); $$=createNode("return_stmt","",{n11, $2});}
|            RETURN {$$=createNode("Keyword","return",{});}

global_stmt: GLOBAL IDENTIFIER comm_name {Node *n1 = createNode("Keyword","Global",{}); Node *n2 = createNode("IDENTIFIER",*$2,{}); $$=createNode("global_stmt","",{n1, n2, $3});}
comm_name:comm_name COMMA IDENTIFIER {$$=$1;Node *n1 = createNode("Delimiter",",",{}); Node *n2 = createNode("IDENTIFIER",*$3,{}); $$->children.push_back(n1);$$->children.push_back(n2);} 
        | {$$=createNode("comm_name", "", {});}
nonlocal_stmt: NONLOCAL IDENTIFIER comm_name {Node *n1 = createNode("Nonlocal","nonlocal",{}); Node *n2 = createNode("IDENTIFIER",*$2,{}); $$=createNode("nonlocal_stmt","",{n1, n2, $3});}
assert_stmt: ASSERT test comma_test_maybe {Node *n1 = createNode("Keyword","Assert",{});  $$=createNode("Assert_stmt","",{n1, $2, $3});}
comma_test_maybe: COMMA test {Node *n1=createNode("Delimiter",",",{}); $$=createNode("comma_testmaybe","",{n1,$2});}| {$$ = createNode("comma_test_maybe",",",{});}

compound_stmt: if_stmt {$$=$1;}| while_stmt{$$=$1;} | for_stmt{$$=$1;} | funcdef{$$=$1;} | classdef{$$=$1;} | async_stmt{$$=$1;}
async_stmt: ASYNC funcdef {Node *n1=createNode("Keyword","Async",{}); $$=createNode("async_stmt","",{n1,$2});}
    | ASYNC for_stmt {Node *n1=createNode("Keyword","Async",{}); $$=createNode("async_stmt","",{n1,$2});}
if_stmt: IF test COLON suite elif_namedexprtest_colon_suite else_colon_suite_maybe {Node *n1=createNode("KEYWORD","if",{}); Node *n2=createNode("Delimiter",":",{}); $$=createNode("If_stmt","",{n1,$2,n2,$4,$5,$6});}
while_stmt: WHILE test COLON suite else_colon_suite_maybe {Node *n1=createNode("Keyword","while",{});Node *n2=createNode("Delimiter",":",{});$$=createNode("while","",{n1,$2,n2,$4,$5});}
for_stmt: FOR exprlist IN RANGE  LPAREN  testlist RPAREN  COLON suite else_colon_suite_maybe {
    Node* n1=createNode("Keyword","For",{});Node* n2=createNode("Keyword","In",{});
    Node* n3=createNode("Keyword","Range",{});Node* n4=createNode("Lparen","(",{});
    Node* n5=createNode("rparen",")",{});Node* n6=createNode("Delimiter",":",{});
    $$=createNode("for","",{n1,$2,n2,n3,n4,$6,n5,n6,$9,$10});}
else_colon_suite_maybe: ELSE COLON suite {Node* n1=createNode("Keyword","Else",{});Node* n2=createNode("Delimiter",":",{});$$=createNode("else","",{n1,n2,$3});}| {$$=createNode("else_colon_suite_maybe","",{});}

elif_namedexprtest_colon_suite: elif_namedexprtest_colon_suite ELIF test COLON suite{$$=$1;Node* n1=createNode("Keyword","Elif",{});Node* n2=createNode("Delimiter",":",{});$$->children.push_back(n1);$$->children.push_back($3);$$->children.push_back(n2);$$->children.push_back($5);} 
                            | {$$=createNode("elif_namedexprtest_colon_suite", "", {});}


suite: simple_stmt {$$=$1;} 
|     NEWLINE INDENT  stmt_morethanone DEDENT {
    Node * n1=createNode("Newline","nl",{});Node * n2=createNode("Indent","Indent",{});Node * n3=createNode("Dedent","Dedent",{});
    $$=createNode("suite","",{n1,n2,$3,n3});
}

stmt_morethanone: stmt_morethanone stmt {$$=$1;$$->children.push_back($2);} | stmt{$$=createNode("stmt_more","",{$1});}
 
test: or_test if_ortest_else_test_maybe {$$=createNode("test","",{$1,$2});}
if_ortest_else_test_maybe: IF or_test ELSE test {
    Node * n1=createNode("Keyword","if",{});Node * n2=createNode("Keyword","else",{});
    $$=createNode("if_or_else","",{n1,$2,n2,$4});
}| {$$ = createNode("if_ortest_else_test_maybe","",{});}
// {cout<<"not1\n";}
or_test: and_test or_andtest {$$=createNode("or_test","",{$1,$2});}
or_andtest: or_andtest OR and_test {$$=$1;Node * n1=createNode("Keyword","or",{});
    $$->children.push_back(n1);$$->children.push_back($3);}
    | {$$=createNode("or_andtest", "", {});} 
// {cout<<"not2\n";}
and_test: not_test and_nottest {$$=createNode("and_test","",{$1,$2});}
and_nottest: and_nottest AND not_test {$$=$1;Node * n1=createNode("Keyword","And",{});
    $$->children.push_back(n1);$$->children.push_back($3);}
    | {$$=createNode("and_nottest", "", {});}
// {cout<<"not3\n";}
not_test: NOT not_test{$$=createNode("Keyword","not",{}); $$->children.push_back($2);} | comparison {$$=$1;}
comparison: expr comp_op_expr {$$=createNode("comp","",{$1,$2});}
// {cout<<"not5\n";} 
comp_op_expr: comp_op_expr comp_op expr {$$=$1;$$->children.push_back($2);$$->children.push_back($3);} 
            | {$$=createNode("comp_op_expr", "", {});}
// {cout<<"not6\n";}

comp_op: 
LT{$$=createNode("Operator","<",{});}
|GT {$$=createNode("Operator",">",{});}
|EQ {$$=createNode("Operator","==",{});}
|GTE {$$=createNode("Operator",">=",{});}
|LTE {$$=createNode("Operator","<=",{});}
|NEQ {$$=createNode("Operator","!=",{});}
|IN {$$=createNode("Keyword","in",{});}
|NOT IN {Node *n1=createNode("Keyword","not",{});Node *n2=createNode("Keyword","in",{});$$=createNode("not in","",{n1,n2});}
|IS {$$=createNode("Keyword","is",{});}
|IS NOT {Node *n1=createNode("Keyword","not",{});Node *n2=createNode("Keyword","is",{});$$=createNode("is not","",{n2,n1});}

star_expr: TIMES expr {Node *n1=createNode("Operator","*",{});$$=createNode("star_expr","",{n1,$2});}
expr: xor_expr bitor_xorexpr {$$=createNode("expr","",{$1,$2});}
bitor_xorexpr: bitor_xorexpr BIT_OR xor_expr {$$=$1;Node * n1=createNode("Bit_op","|",{});
    $$->children.push_back(n1);$$->children.push_back($3);}
    | {$$=createNode("bitor_xorexpr", "", {});}
xor_expr: and_expr bitxor_andexpr {$$=createNode("expr","",{$1,$2});}
bitxor_andexpr: bitxor_andexpr BIT_XOR and_expr {$$=$1;Node * n1=createNode("Bit_op","^",{});
    $$->children.push_back(n1);$$->children.push_back($3);} | {$$=createNode("bitxor_andexpr", "", {});}
and_expr: shift_expr bitand_shiftexpr {$$=createNode("expr","",{$1,$2});}
bitand_shiftexpr: bitand_shiftexpr BIT_AND shift_expr {$$=$1;Node * n1=createNode("Bit_op","&",{});
    $$->children.push_back(n1);$$->children.push_back($3);}| {$$=createNode("bitand_shiftexpr", "", {});}
shift_expr: arith_expr lorrshift_arithexpr {$$=createNode("expr","",{$1,$2});}

lorrshift_arithexpr: lorrshift_arithexpr lshift_or_rshift arith_expr {$$=$1;$$->children.push_back($2);$$->children.push_back($3);} | {$$=createNode("lorrshift_arithexpr", "", {});}
lshift_or_rshift: BIT_LSHIFT {$$=createNode("Bit_left_shift","<<",{});} | BIT_RSHIFT {$$=createNode("Bit_right_shift",">>",{});}
arith_expr: term plusorminus_term {$$=createNode("arith_expr","",{$1,$2});}
plusorminus_term: plusorminus_term plus_or_minus term  {$$=$1;$$->children.push_back($2);$$->children.push_back($3);} | {$$=createNode("plusorminus_term", "", {});}
plus_or_minus: PLUS {$$=createNode("Operator","+",{});}| MINUS {$$=createNode("Operator","-",{});}
term: factor timedivmod_factor {$$=createNode("term","",{$1,$2});}
timedivmod_factor: timedivmod_factor timedivmod factor {$$=$1;$$->children.push_back($2);$$->children.push_back($3);}| {$$=createNode("timedivmod_factor", "", {});}
timedivmod: TIMES{$$=createNode("Operator","*",{});}|DIVIDEDBY{$$=createNode("Operator","/",{});}|MODULO{$$=createNode("Operator","%",{});}|MOD {$$=createNode("Operator","//",{});}
factor: plusminusnot factor {$$=$1; $$->children.push_back($2);} | power {$$=$1;}
plusminusnot: PLUS {$$=createNode("Operator","+",{});}| MINUS {$$=createNode("Operator","-",{});}| BIT_NOT{$$=createNode("Operator","~",{});}
power: atom_expr pow_factor_maybe {$$=createNode("power","",{$1,$2});}
pow_factor_maybe: POW factor {Node *n1=createNode("Operator","**",{});$$=createNode("pow_maybe","",{n1,$2});} | {$$=createNode("pow_maybe","",{});}
atom_expr: AWAIT atom trailer_ {Node *n1=createNode("KEYWORD","AWAIT",{});$$=createNode("atom_expr","",{n1,$2});} | atom trailer_ {$$=createNode("atom_expr","",{$1,$2});}
trailer_: trailer_ trailer {$$=$1;$$->children.push_back($2);}| {$$=createNode("trailer_", "", {});}
atom: LPAREN testlist_comp RPAREN {Node *n1=createNode("Delimiter","(",{});Node *n2=createNode("Delimiter",")",{});$$=createNode("atom","",{n1,$2,n2});}|
        LEN LPAREN testlist_comp RPAREN {Node *n3=createNode("KEYWORD","len",{});Node *n1=createNode("Delimiter","(",{});Node *n2=createNode("Delimiter",")",{});$$=createNode("atom","",{n3,n1,$3,n2});} |
        //IDENTIFIER LPAREN testlist_comp RPAREN |
       LLIST  testlist_comp RLIST  {Node *n1=createNode("Delimiter","[",{});Node *n2=createNode("Delimiter","]",{});$$=createNode("atom","",{n1,$2,n2});}|
       IDENTIFIER {$$=createNode("Identifer",*$1,{});} | NUMBER {$$=createNode("Number",*$1,{});}| string_pl{$$=$1;}| FLOATING_POINT {$$=createNode("FLoating_point",*$1,{});}
       //| '...' 
       | NONE {$$=createNode("KEYWORD","None",{});} | TRUE {$$=createNode("KEYWORD","True",{});} | FALSE {$$=createNode("KEYWORD","False",{});}


string_pl: string_pl STR_LIT {$$=$1;Node * n1= createNode("Str",*$2,{});$$->children.push_back(n1);} | STR_LIT {$$= createNode("Str",*$1,{});}
testlist_comp: {$$=createNode("testlist_comp","",{});}|test  testlist_comp_a {$$=createNode("testlist_comp","",{$1,$2});}| star_expr testlist_comp_a {$$=createNode("testlist_comp","",{$1,$2});}
testlist_comp_a: comp_for {$$=$1;}| comma_testorstar COMMA {Node *n1=createNode("Delimiter",",",{});$$=createNode("testlist_comp_a","",{$1,n1});} | comma_testorstar {$$=$1;}
comma_testorstar: comma_testorstar COMMA test_or_starexpr {
    $$=$1;
    Node *n1=createNode("Delimiter",",",{});
    $$->children.push_back(n1); $$->children.push_back($3);
} | {$$=createNode("comma_testorstar", "", {});}
test_or_starexpr: test {$$=$1;}| star_expr{$$=$1;}
trailer: LPAREN arglist RPAREN { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                $$=createNode("trailer", "", {n1, $2, n2});}
                                | LPAREN RPAREN { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                $$=createNode("trailer", "", {n1, n2});}
                                | LLIST subscriptlist RLIST { Node *n1=createNode("Delimiter", "[", {}); 
                                Node *n2=createNode("Delimiter", "]", {});
                                $$=createNode("trailer", "", {n1, $2, n2});}
                                | DOT IDENTIFIER { Node *n1=createNode("Delimiter", ".", {}); 
                                Node *n2=createNode("Identifer", *$2, {});
                                $$=createNode("trailer", "", {n1, n2});}
subscriptlist: subscript comma_subscript COMMA { Node *n1=createNode("Delimiter", ",", {});
                                $$=createNode("subscriptlist", "", {$1, $2, n1});}
                                | subscript comma_subscript { $$=createNode("subscriptlist", "", {$1, $2});}
comma_subscript: comma_subscript COMMA subscript { $$=$1; Node *n1=createNode("Delimiter", ",", {});
                                $$->children.push_back(n1); $$->children.push_back($3);}| {$$=createNode("comma_subscript", "", {});}
subscript: test{$$=$1;} | test COLON test sliceop_maybe { Node *n1=createNode("Delimiter", ":", {});
                                $$=createNode("subscript", "", {$1, n1, $3, $4});}
                                | test COLON sliceop_maybe { Node *n1=createNode("Delimiter", ":", {});
                                $$=createNode("subscript", "", {$1, n1, $3});}
                                | COLON test sliceop_maybe { Node *n1=createNode("Delimiter", ":", {});
                                $$=createNode("subscript", "", {n1, $2, $3});}
                                | COLON sliceop_maybe { Node *n1=createNode("Delimiter", ":", {});
                                $$=createNode("subscript", "", {n1, $2});}
sliceop_maybe: sliceop {$$=$1;}| {$$=createNode("sliceop_maybe","",{});}
sliceop: COLON test { Node *n1=createNode("Delimiter", ":", {}); $$=createNode("sliceop", "", {n1, $2});}| COLON {$$=createNode("Delimiter", ":", {});}
exprlist: expr_str comm_exstr COMMA { Node *n1=createNode("Delimiter", ",", {}); $$=createNode("exprlist", "", {$1, $2, n1});}| expr_str comm_exstr {$$=createNode("exprlist", "", {$1, $2});}
expr_str: expr{$$=$1;}|star_expr{$$=$1;}
comm_exstr: comm_exstr COMMA expr_str {$$=$1; Node *n1=createNode("Delimiter", ",", {}); $$->children.push_back(n1); $$->children.push_back($3);} | {$$=createNode("comm_exstr", "", {});}
testlist: test comm_test COMMA { Node *n1=createNode("Delimiter", ",", {}); $$=createNode("testlist", "", {$1, $2, n1});} | test comm_test {$$=createNode("testlist", "", {$1, $2});}
comm_test: comm_test COMMA test {$$=$1; Node *n1=createNode("Delimiter", ",", {}); $$->children.push_back(n1); $$->children.push_back($3);} | {$$=createNode("comm_test", "", {});}
dictorsetmaker: testcoltest_powexpr compfor_comtestpowcom {$$=createNode("dictorsetmaker", "", {$1, $2});}|  test_or_starexpr compfor_comteststarcom {$$=createNode("dictorsetmaker", "", {$1, $2});}

compfor_comtestpowcom: comp_for {$$=$1;}| comma_testpow COMMA { Node *n1=createNode("Delimiter", ",", {}); $$=createNode("compfor_comtestpowcom", "", {$1, n1});}| comma_testpow {$$=$1;}
compfor_comteststarcom: comp_for {$$=$1;}| comma_testorstar COMMA { Node *n1=createNode("Delimiter", ",", {}); $$=createNode("compfor_comteststarcom", "", {$1, n1});} | comma_testorstar {$$=$1;}
testcoltest_powexpr: test COLON test { Node *n1=createNode("Delimiter", ":", {}); $$=createNode("testcoltest_powexpr", "", {$1, n1, $3});} | POW expr { Node *n1=createNode("Operator", "**", {}); $$=createNode("testcoltest_powexpr", "", {n1, $2});}
comma_testpow: comma_testpow COMMA testcoltest_powexpr { $$=$1;Node *n1=createNode("Delimiter", ",", {}); $$->children.push_back(n1);$$->children.push_back($3);} | {$$ = createNode("comma_testpow","",{});} 
classdef: CLASS IDENTIFIER l_arglist_r_maybe COLON  suite { Node *n1=createNode("KEYWORD", "CLASS", {}); 
                                                            Node *n2=createNode("Identifier", *$2, {});
                                                            Node *n3=createNode("Delimiter", ":", {});
                                                            $$=createNode("classdef", "", {n1, n2, $3, n3, $5});}
l_arglist_r_maybe: LPAREN arglist RPAREN { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                $$=createNode("l_arglist_r_maybe", "", {n1, $2, n2});} | {$$=createNode("l_arglist_r_maybe", "", {});}

arglist: argument comm_arg COMMA { Node *n1=createNode("Delimiter", ",", {}); $$=createNode("arglist", "", {$1, $2, n1});} | argument comm_arg {$$=createNode("arglist", "", {$1, $2});}
comm_arg: comm_arg COMMA argument {$$=$1; Node *n1=createNode("Delimiter", ",", {}); $$->children.push_back(n1); $$->children.push_back($3);}| {$$=createNode("comm_arg", "", {});}
argument:  test comp_for {$$=createNode("argument", "", {$1, $2});}|
            test {$$=$1;}|
            test EQUALS test { Node *n1=createNode("Equals", "=", {}); $$=createNode("argument", "", {$1, n1, $3});}|
            POW test { Node *n1=createNode("Operator", "**", {}); $$=createNode("argument", "", {n1, $2});}|
            TIMES test { Node *n1=createNode("Operator", "*", {}); $$=createNode("argument", "", {n1, $2});}

comp_iter: comp_for {$$=$1;}| comp_if{$$=$1;}
sync_comp_for: FOR exprlist IN or_test comp_iter { Node *n1=createNode("KEYWORD", "FOR", {}); 
                                                    Node *n2=createNode("KEYWORD", "IN", {});
                                                    $$=createNode("sync_comp_for", "", {n1, $2, n2, $4, $5});}
| FOR exprlist IN or_test { Node *n1=createNode("KEYWORD", "FOR", {}); 
                                                    Node *n2=createNode("KEYWORD", "IN", {});
                                                    $$=createNode("sync_comp_for", "", {n1, $2, n2, $4});}
comp_for: ASYNC sync_comp_for { Node *n1=createNode("KEYWORD", "ASYNC", {}); 
                                $$=createNode("comp_for", "", {n1, $2});}
        | sync_comp_for {$$=$1;}
comp_if: IF or_test comp_iter { Node *n1=createNode("KEYWORD", "IF", {}); 
                                $$=createNode("comp_if", "", {n1, $2, $3});}
                                |  IF or_test { Node *n1=createNode("KEYWORD", "IF", {}); 
                                $$=createNode("comp_if", "", {n1, $2});}

// # not used in grammar, but may appear in "node" passed from Parser to Compiler
encoding_decl: IDENTIFIER {$$=createNode("encoding_decl",*$1,{});}

func_body_suite: simple_stmt {$$=$1;}| NEWLINE INDENT stmt_morethanone DEDENT {
    Node * n1=createNode("Newline","nl",{});Node * n2=createNode("Indent","Indent",{});Node * n3=createNode("Dedent","Dedent",{});
    $$=createNode("func_body_suite","",{n1,n2,$3,n3});
}

func_type_input: func_type nls ENDMARKER {
    Node * n1=createNode("Endmarker","<<EOF>>",{}); $$=createNode("func_type_input","",{$1,$2,n1});
}
nls: nls NEWLINE {$$=$1; Node *n1 = createNode("Newline","nl",{}); $$->children.push_back(n1);}| {$$=createNode("nls", "", {});}
func_type: LPAREN typelist RPAREN R_ARR test { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                Node *n3=createNode("RArrow", "->", {});
                                $$=createNode("func_type", "", {n1, $2, n2, n3, $5});}
        | LPAREN RPAREN R_ARR test { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                Node *n3=createNode("RArrow", "->", {});
                                $$=createNode("func_type", "", {n1, n2, n3, $4});}
// # typelist is a modified typedargslist (see above)
typelist: test comm_test comma_typel_maybe {$$=createNode("typelist", "", {$1, $2, $3});}
     |  TIMES test comm_test comma_pow_test_maybe { Node *n1=createNode("Operator", "*", {}); $$=createNode("func_type", "", {n1, $2, $3, $4});}
     | TIMES comm_test comma_pow_test_maybe { Node *n1=createNode("Operator", "*", {}); $$=createNode("func_type", "", {n1, $2, $3});}
     | POW test { Node *n1=createNode("Operator", "**", {}); $$=createNode("func_type", "", {n1, $2});}
comma_typel_maybe: COMMA type_l { Node *n1=createNode("Delimiter", ",", {}); $$=createNode("comma_typel_maybe", "", {n1, $2});}
                | COMMA { $$=createNode("Delimiter", ",", {});}| {$$=createNode("comma_typel_maybe", "", {});}
type_l: TIMES test comm_test comma_pow_test_maybe { Node *n1=createNode("Operator", "*", {}); $$=createNode("type_l", "", {n1, $2, $3, $4});}
        | TIMES comm_test comma_pow_test_maybe { Node *n1=createNode("Operator", "*", {}); $$=createNode("type_l", "", {n1, $2, $3});}
        | POW test { Node *n1=createNode("Operator", "**", {}); $$=createNode("type_l", "", {n1, $2});}
comma_pow_test_maybe: COMMA POW test {Node *n1=createNode("Delimiter",",",{});Node *n2=createNode("Operator","*",{});$$=createNode("comma_pow_test_maybe","",{n1,n2,$3});}| {$$=createNode("comma_pow_test_maybe","",{});}
%%




int node_counter = 0;
string dfs(Node* node,ofstream &out) {
    // Generate the label for the current node
    
    if(node->children.size()==1) return dfs(node->children[0], out);
        if(node->children.size()==2){
            if(node->children[1]->children.empty() && node->children[1]->value.empty()) return dfs(node->children[0],out);
            if(node->children[0]->children.empty() && node->children[0]->value.empty()) return dfs(node->children[1],out);
        }
        // if(parent!=NULL and parent->children.size()==2){
        //     if (node==parent->children[0]){
        //         if(parent->children[1]->children.size()==1 and parent->children[1]->value.empty()){

        //         }
        //     }
        // }
        string node_name = "node_" + to_string(node_counter++);
        
        
        string temp;
        if ((node->value)[0] == '"') {
            temp = "\\" + node->value.substr(0, node->value.size() - 1) + "\\\"";
        } else {
            temp = node->value;
        }
        string node_label = node->value.empty() ? node->label : node->label + "(" + temp+")";
        if(!node->children.empty() or !node->value.empty())
            out << node_name << " [label=\"" << node_label << "\"]" << endl;

        for (auto child : node->children) {
            if(child->value.empty() && child->children.empty()) continue;
            string child_name = dfs(child,out);
            out << node_name << " -> " << child_name << endl;
        }
        
        return node_name;
    }


void print_path(Node *node,int t){
    if (node== nullptr){
        return;
    }
    for(int i=0; i<t; i++){
        cout<<'\t';
    }
    cout<<(node->label+"("+node->value+")")<<" -> ";
    for(auto i: node->children){
        cout<<(node->label+"("+node->value+")")<<" ";
    }
    cout<<endl;
    t++;
    for(auto child:node->children){
        print_path(child,t);
    }


}

void generateDotFile(string outp) {
    if (root == nullptr) {
        return;
    }
    ofstream out(outp);
    // out.open()
    out << "digraph G {" << endl;
    out << "  node [shape=ellipse, style=filled, fillcolor=white]" << endl;
    
   

    dfs(root,out);

    out << "}" << endl;
    out.close();
}


void print_help() {
    cout << "Usage options     \n\n";
    cout << "Commands:\n-h, --help \t\t\t\t\t help and options\n";
    cout << "-i, --input <input_file_name> \t\t\t Give input file\n";
    cout << "-o, --output <output_file_name>\t\t\t Redirect dot file to output file\n";
    cout << "-v, --verbose \t\t\t\t\t Outputs the entire derivation in command line\n";
    return;
}


int main (int argc, char *argv[]) {
    bool verbose=false;
    for(int i = 1; i < argc; i++){        
        if(std::string(argv[i]) == "--help" || std::string(argv[i]) == "-h") {
            print_help();
            return -1;
        }
        else if(std::string(argv[i]) == "--input" || std::string(argv[i]) == "-i") {
            if((i + 1) < argc) input_file = argv[i+1];
            else {cout << "Error: No input filename given";return -1;}
            i++;
        }
        else if(std::string(argv[i]) == "--output" || std::string(argv[i]) == "-o") {
            if((i + 1) < argc) output_file = argv[i+1];
            else {cout << "Error: No output filename given";return -1;}
            i++;
        }
        else if(std::string(argv[i]) == "--verbose" || std::string(argv[i]) == "-v") {
            verbose = true;
        }
        else {
            cout << "Error: Invalid parameter\n";
            print_help();
            return -1;
        }
    }
    program = fopen(input_file.c_str(), "r");
    if(!program) {
        cout << "Error: Program file could not be opened" << endl;
        return -1;
    }

    yyin = program;
    yyout = stderr;
    yylex();
    if(verbose){
        print_path(root,0);
    }
    //cout<<"done\n";
    generateDotFile(output_file);
    fclose(program);
    return 1;
}
