%{
    #include<bits/stdc++.h>
    using namespace std;
    // #include "ast1.h"
    #include "x86.h"
    extern int yylex();
    #define YYERROR_VERBOSE 1
    // extern int yyparse();
    extern FILE *yyin;
    extern int yylineno;
    extern int yydebug;
    extern symbol_table_global * main_st;
    extern symbol_table_global* ogroot;
    extern symbol_table* orig;
    extern symbol_table *curr;
    extern FILE *yyout;
    vector<quad*> ircode;
    int tac_line=0;
    FILE *program;
    string input_file = "../tests/testcase1.py";
    string output_file = "asm.s";
    string asm_file="asm.s"; 
    codegen* gen= new codegen();
    int temp_cnt=0;
    int is_funccall=0;
    int is_ctorcall=0;
    int is_print_string=0;
    string trailer_attr="";


    void yyerror(const char *s) {
 
    fprintf(stderr, "Error at line %d: %s\n",yylineno, s);}
    extern Node *root;

Node *createNode(string label, string value, vector <Node *> children) {

    Node *temp = new Node();
    temp->value = value;
    temp->children = children;
    temp->label = label;
    temp->line_no=yylineno;

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

%token <str> IDENTIFIER DELIMITER  FLOATING_POINT NUMBER TRUE FALSE TYPE STR_LIT BYT_LIT STR LIST FLOAT BOOL NONE
%token <token> EQUALS PLUS MINUS TIMES DIVIDEDBY NEWLINE MOD MODULO AUGPLUS AUGMINUS AUGTIMES AUGDIVIDEDBY AUGMOD AUGMODULO POW AUGPOW
%token <token> BIT_AND BIT_OR BIT_XOR BIT_NOT BIT_RSHIFT BIT_LSHIFT AUGBIT_AND AUGBIT_OR AUGBIT_XOR AUGBIT_NOT AUGBIT_RSHIFT AUGBIT_LSHIFT
%token <token> LPAREN RPAREN COMMA DOT COLON SEMICOLON LLIST RLIST R_ARR
%token <token> EQ NEQ GT GTE LT LTE HEX INT AWAIT LEN 
%token <token> AND BREAK DEF ELIF ELSE FOR IF ENDMARKER RANGE
%token <token> NOT OR RETURN WHILE INDENT DEDENT IS IN CONTINUE ASSERT NONLOCAL GLOBAL CLASS ASYNC 
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
file: single_inputs{Node * temp=createNode("EOF","<EOF>",{}); 
                    root =createNode("file","",{$1,temp});
                    orig->make_csv_wrapper();$$=root;
                    // for(auto qq:ircode) cout<<"done done "<<qq->code; 
                    $$->code = $1->code;
                    ofstream tac_file("tac3.txt");
                    int linenum=1;
                    set<int> targets;
                    for(auto tx: $$->code){
                        size_t found=tx->code.find("goto");
                        tx-> ins_line = linenum;
                        string final;
                        if(found!=string::npos){
                            final=tx->code.substr(0,(int)found+4);
                            int fin=linenum;
                            string n="";
                            int ch=1;
                            for(int i=found+5;i<tx->code.size();i++){
                                if(tx->code[i]=='-') ch=-1;
                                if(tx->code[i]>='0' and tx->code[i]<='9') n+=tx->code[i];
                            }
                            fin+=ch*stoi(n);
                            final+=(" "+to_string(fin)+"\n");
                            // tx->code=final;
                            // op="goto";
                            // arg1="j+"+to_string();
                            // quad* q1=new quad("",arg1,op,"");
                            // q1->make_code_from_goto();
                            tx->abs_jump = fin;
                            targets.insert(fin);

                        }
                        else
                         final=tx->code;
                        tac_file<<linenum<<":"<<final;
                        linenum++;
                    }
                    int linum=1;
                    for(auto tx: $$->code){
                        if(targets.find(linum)!= targets.end()) tx->is_target = true;
                        linum++;
                    }
                    tac_file.close();
                    gen->gen_global();
                    gen->gen_text();
                    gen->print_code(output_file);
                    }  
|     func_type_input {Node * temp=createNode("EOF","<EOF>",{}); root =createNode("file","",{$1,temp});}
;
single_inputs : single_inputs single_input { $$=$1; $$->children.push_back($2); $$->code = $1->code; $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());}
|               single_input {$$=createNode("single_inputs","",{$1}); $$->code = $1->code;}
single_input: NEWLINE {$$=createNode("Newline","nl",{});}
|             simple_stmt {$$=$1;}
|             compound_stmt{$$=$1;}
|             compound_stmt NEWLINE{Node *n1=createNode("Newline","nl",{}); $$=createNode("single_input","",{$1,n1});}
;
async_funcdef: ASYNC funcdef {Node* n1=createNode("Keyword","async",{});$$=createNode("Async_func","",{n1,$1});}
funcdef: DEF IDENTIFIER parameters rarr_test_maybe {
    // cout<<"def\n";
    symbol_table_func* funcd=new symbol_table_func(*$2,$3->Sym_list,$4->type);
    if(curr->st_category!='C') ogroot->add_entry(funcd);
    else {
        symbol_table_class* cls=(symbol_table_class *)curr;
        cls->add_func(funcd);
    }                                                                                                                                                                                                      
    curr->add_scope(funcd);
    Symbol* fn=new Symbol(*$2,$4->type,yylineno); 
    fn->is_func=true;curr->add_entry(fn);curr=funcd;
    }  COLON func_body_suite{
        // cout<<"abort0\n";
        // symbol_table_func* funcf=(symbol_table_func *)curr;
        Node* n2= createNode("Keyword","def",{});
        Node* n3= createNode("Identifier",*$2,{});
        Node* n4= createNode("Delimiter",":",{});
        $$=createNode("Func","",{n2,n3,$3,$4,n4,$7});
        curr=curr->parent;
        
        string arg1=*$2;
        string argg1 = arg1;
        if (curr->st_category=='C'){
            argg1=curr->name+"."+arg1;
        }
        quad* q = new quad("", argg1, "", "");
        q->make_code_begin_func();
        $$->code.push_back(q);
        // funcf->codes.push_back(q);
        // cout<<"abort\n";
        if(curr->st_category == 'C' && arg1!="__init__"){
            // cout<<"notinit"<<endl;
            quad* q2 = new quad("self", "", "", "");
            q2->make_code_pop_param();
            $$->code.push_back(q2);
            // funcf->codes.push_back(q2);
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q3 = new quad(tar, "self", "", "");
            q3->make_code_from_assignment();
            $$->code.push_back(q3);
            // funcf->codes.push_back(q3);
            vector<quad*> temp;
            int ctr=0;
            for(auto cd:$7->code){
                if(cd->made_from==quad::ASSIGNMENT){
                    if(cd->self_res == true && cd->self_arg1 == false){
                        string tar1=tar;
                        if(ctr==0){
                            // tar1=tar;
                        }
                        // string tar=cd->result
                        else{
                            string tar2=string("_t")+to_string(temp_cnt);
                            temp_cnt++;
                            quad* q5 = new quad(tar2, tar, "+", to_string(ctr*8));
                            q5->make_code_from_binary();
                            // temp.push_back(q5);
                            // tar1=tar2;
                        }
                        // cout<<"done"<<endl;
                        string class_name = curr->name;
                        symbol_table_class * cls=ogroot->look_up_class(class_name);
                        int offset=0;
                        bool found=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==cd->result){
                                found=true;
                                break;
                            }
                            offset++;
                        }
                        // cout<<"offset"<<offset<<endl;
                        string a1=cd->arg1;
                        string arg2="";
                        if(found){
                        // cout<<"done2"<<endl;
                            if(offset) arg2=to_string(8*offset);
                            // cout<<arg2<<endl;
                            quad* qn=new quad(tar1,a1,"",arg2);
                            qn->make_code_from_store();
                            temp.push_back(qn);
                            // cout<<qn->code<<endl;
                            ctr++;
                        }
                    // cout<<"done3"<<endl;
                    }
                    else if(cd->self_arg1 == true && cd->self_res == false){
                        string tar1=tar;
                        // if(ctr==0){
                        //     // tar1=tar;
                        // }
                        // // string tar=cd->result
                        // else{
                        //     string tar2=string("_t")+to_string(temp_cnt);
                        //     // temp_cnt++;
                        //     quad* q5 = new quad(tar2, tar, "+", to_string(ctr*8));
                        //     q5->make_code_from_binary();
                        //     // temp.push_back(q5);
                        //     // tar1=tar2;
                        // }
                        string class_name = curr->name;
                        symbol_table_class * cls=ogroot->look_up_class(class_name);
                        int offset=0;
                        bool found=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==cd->arg1){
                                found=true;
                                break;
                            }
                            offset++;
                        }
                        // cout<<"offset"<<offset<<endl;
                        string a1=cd->arg1;
                        string arg2="";
                        // cout<<cd->arg1<<" "<<cd->arg2<<" "<<cd->result<<endl;
                        if(found){
                            if(offset) arg2=to_string(8*offset);
                            // cout<<arg2<<endl;
                            quad* qn=new quad(cd->result,tar1,"",arg2);
                            qn->make_code_from_load();
                            // cout<<qn->code<<endl;
                            temp.push_back(qn);
                            ctr++;
                        }
                    }
                    else if(cd->self_arg1 == true && cd->self_res == true){
                        string tar1;
                        if(ctr==0){
                            tar1=tar;
                        }
                        // string tar=cd->result
                        else{
                            string tar2=string("_t")+to_string(temp_cnt);
                            temp_cnt++;
                            quad* q5 = new quad(tar2, tar, "+", to_string(ctr*8));
                            q5->make_code_from_binary();
                            temp.push_back(q5);
                            tar1=tar2;
                        }
                        string class_name = curr->name;
                        symbol_table_class * cls=ogroot->look_up_class(class_name);
                        int offset1=0;
                        bool found1=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==cd->result){
                                found1=true;
                                break;
                            }
                            offset1++;
                        }
                        int offset2=0;
                        bool found2=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==cd->arg1){
                                found2=true;
                                break;
                            }
                            offset2++;
                        }
                        // cout<<offset1<<" "<<offset2<<endl;
                        // cout<<"offset"<<offset<<endl;
                        string a1=cd->arg1;
                        string arg2="";
                        string argg2="";
                        // cout<<cd->arg1<<" "<<cd->arg2<<" "<<cd->result<<endl;
                        if(found1 && found2){
                            if(offset1) arg2=to_string(8*offset1);
                            if(offset2) argg2=to_string(8*offset2);
                            // cout<<arg2<<endl;
                            string tarx=string("_t")+to_string(temp_cnt);
                            temp_cnt++;
                            quad* qn=new quad(tarx,tar1,"",argg2);
                            qn->make_code_from_load();
                            temp.push_back(qn);
                            quad* qnn=new quad(tar1,tarx,"",arg2);
                            qnn->make_code_from_store();
                            temp.push_back(qnn);
                            ctr++;
                        }
                    }
                    else{
                        temp.push_back(cd);
                    }
                }
                else if (cd->made_from==quad::RETURN){
                    if(cd->self_arg1 == true){
                        string argu1=cd->arg1;
                        string class_name = curr->name;
                        symbol_table_class * cls=ogroot->look_up_class(class_name);
                        int offset=0;
                        bool found=false;
                        for(auto it:cls->attrs){
                            if(it->lexeme==argu1){
                                found=true;
                                break;
                            }
                            offset++;
                        }
                        // cout<<"offset"<<offset<<endl;
                        if(found){
                            string arg2="";
                            if(offset) arg2=to_string(8*offset);
                            string res=tar;
                            string tar2=string("_t")+to_string(temp_cnt);
                            temp_cnt++;
                            quad* ql = new quad(tar2, res, "", arg2);
                            ql->make_code_from_load();
                            temp.push_back(ql);
                            string op="return";
                            quad* qr = new quad("", tar2, op, "");
                            qr->make_code_from_return();
                            temp.push_back(qr);
                        }
                    }
                    else{
                    temp.push_back(cd);
                    }
                }
                else{
                    temp.push_back(cd);
                }
            }
            $7->code=temp;
        }
        // cout<<"abort1\n";
        bool fl=0;
        if(arg1 == "__init__") {
            if(curr->st_category!='C') yyerror("__init__ defined outside class");
            else argg1 = curr->name + '.' + arg1;

            // cout<<"polle\n";
            fl=1;
        }
        // cout<<"abort2\n";
        if(fl) {
            // cout<<curr->st_category<<"inside init\n";
            symbol_table_func * funcd=curr->look_upfunc("__init__");
            symbol_table_class *clss=(symbol_table_class *)curr;
            for(auto it:funcd->entries) {
                // cout<<"funcd\n";
                clss->attrs.push_back(it);
            }
            quad* q2 = new quad("self", "", "", "");
            q2->make_code_pop_param();
            $$->code.push_back(q2);
            // funcf->codes.push_back(q2);
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q3 = new quad(tar, "self", "", "");
            q3->make_code_from_assignment();
            $$->code.push_back(q3);
            // funcf->codes.push_back(q3);
            vector<quad*> temp;
            int ctr=0;
            for(auto cd:$7->code){
                // cout<<cd->code<<endl;
                // cout<<self_res<<" "<<self_arg1<<" "<<self_arg2<<endl;
                if(cd->made_from==quad::ASSIGNMENT){
                    string tar1;
                    if(ctr==0){
                        tar1=tar;
                    }
                    // string tar=cd->result
                    else{
                        string tar2=string("_t")+to_string(temp_cnt);
                        temp_cnt++;
                        quad* q5 = new quad(tar2, tar, "+", to_string(ctr*8));
                        q5->make_code_from_binary();
                        temp.push_back(q5);
                        tar1=tar2;
                    }
                    string a1=cd->arg1;
                    quad* qn=new quad(tar1,a1,"","");
                    qn->make_code_from_store();
                    temp.push_back(qn);
                    ctr++;
                }
            }
            $7->code=temp;
        }
        // cout<<"abort3\n";
        $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
        // funcf->codes.insert(funcf->codes.end(), $3->code.begin(), $3->code.end());
        ircode.push_back(q);
        $$->code.insert($$->code.end(), $7->code.begin(), $7->code.end());
        // funcf->codes.insert(funcf->codes.end(), $7->code.begin(), $7->code.end());
        quad* q1 = new quad("", "", "", "");
        q1->make_code_end_func(); 
        $$->code.push_back(q1);
        // for(auto cd: $$->code){
        //     cout<<cd->code<<endl;
        // }
        // funcf->codes.push_back(q1);
        
        // for(auto cd:$$->code) cout<<"func "<<cd->code<<endl;
    }
rarr_test_maybe: R_ARR type{Node * n5= createNode("Delimiter","->",{});$$=createNode("rarr_maybe","",{n5,$2});$$->type=$2->type;} | {$$=createNode("rarr_test_maybe","",{});}
parameters: LPAREN typedargslist RPAREN {Node *n6= createNode("Delimiter","(",{});Node *n7= createNode("Delimiter",")",{});$$=createNode("params","",{n6,$2,n7});$$->Sym_list=$2->Sym_list; $$->code=$2->code;};
arguments: argument_a comm_arg_a {
    $$=createNode("args","",{$1,$2});
    $$->Sym_list.push_back($1->sym);
    for(auto &sy:$2->Sym_list) $$->Sym_list.push_back(sy);
    
    $$->code = $1->code;
    $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
    }
argument_a: tfpdef equals_test_maybe{$$=createNode("arg","",{$1,$2}); $$->sym = $1->sym; $$->code=$1->code;}
comm_arg_a: comm_arg_a COMMA argument_a {$$=$1; Node *n1=createNode("Delimiter", ",", {}); $$->children.push_back(n1); $$->children.push_back($3); $$->Sym_list.push_back($3->sym); $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());}| {$$=createNode("comm_arg_a", "", {});}

equals_test_maybe: EQUALS test {Node *n8=createNode("Assign","=",{});$$=createNode("args","",{n8,$2});} | {$$=createNode("equals_test_maybe","",{});} 
kwargs: POW tfpdef comma_maybe {Node *n9=createNode("Operator","Power(**)",{});  $$=createNode("args","",{n9,$2,$3}); $$->sym = $2->sym;} 
comma_maybe: COMMA {Node *n10=createNode("COMMA",",",{});} | {$$=createNode("comma_maybe","",{});} 
args:TIMES tfpdef {   Node *n11 = createNode("Operator","Times(*)",{});
                        $$=createNode("args","",{n11,$2}); $$->sym = $2->sym;}
    | TIMES {Node *n11 = createNode("Operator","Times(*)",{});
            $$ = createNode("args","",{n11});
                    };
kwonly_kwargs:comm_arg_a comma_kwargs_maybe { $$=createNode("kwarg","",{$1,$2});}
comma_kwargs_maybe: COMMA kwargs{   Node *n12 = createNode("Delimiter",",",{});
                                        $$ = createNode("kwargs","",{n12,$2}); $$->sym = $2->sym;
                                    } 
                    | COMMA{$$ = createNode("Delimiter",",",{});}
                    | {$$=createNode("comma_kwargs_maybe","",{});} 
args_kwonly_kwargs: args kwonly_kwargs { $$=createNode("args_kw","nkw",{$1,$2});}
                    |kwargs { $$=$1;};
poskeyword_args_kwonly_kwargs: arguments comma_argskwonlykwargs { $$=createNode("poskeyword_args_kwonly_kwargs","",{$1,$2});$$->Sym_list=$1->Sym_list; $$->code = $1->code;}
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
                                    $$=createNode("tfpdef","",{n11,$2});
                                    Symbol * sym=new Symbol(*$1,$2->type,yylineno);
                                    $$->sym=sym;
                                    string result=*$1;
                                    if(result!="self"){
                                    quad* q = new quad(result, "", "", "");
                                    q->make_code_pop_param();
                                    $$->code.push_back(q);
                                    }
                                    // ircode.push_back(q);
                                    }
colon_test_maybe: COLON type {Node *n11 = createNode("Delimiter",":",{});
                                                         $$=createNode("colon_test_yes","",{n11,$2});$$->type=$2->type;}
                | {$$=createNode("colon_test_maybe","",{});}
// simple_stmts : simple_stmts simple_stmt {$$ = $1;$$->children.push_back($2);}
// |              simple_stmt {$$ = createNode("simple_stmts", "", {$1});}
stmt: simple_stmt{ $$ = $1;} 
|     compound_stmt{$$ = $1;}
simple_stmt: small_stmt small_stmt1 SEMICOLON NEWLINE  { Node* n3= createNode("Delimiter",";",{}); Node* n4= createNode("newline","nl",{});$$=createNode("simple_stmt","",{$1,$2,n3,n4});} 
|            small_stmt small_stmt1 NEWLINE { Node* n3= createNode("newline","nl",{});$$=createNode("simple_stmt","",{$1,$2,n3}); $$->code=$1->code; $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());} 
|            small_stmt small_stmt1 SEMICOLON { { Node* n3= createNode("Delimiter",";",{}); $$=createNode("simple_stmt","",{$1,$2,n3});} }
|            small_stmt small_stmt1 {$$=createNode("simple_stmt","",{$1,$2}); $$->sym = $1->sym; $$->code=$1->code; $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());} 

small_stmt1: small_stmt1 SEMICOLON small_stmt { $$=$1; Node* n1= createNode("Delimiter",";",{}); $$->children.push_back(n1); $$->children.push_back($3);}
| {$$=createNode("small_stmt1", "", {});}

small_stmt: expr_stmt {$$ = $1;}
    //| pass_stmt
    | flow_stmt {$$ = $1;}
    //| import_stmt 
    | global_stmt {$$ = $1;}
    | nonlocal_stmt {$$ = $1;}
    | assert_stmt {$$ = $1;} 


type1: INT {$$=createNode("Keyword","int",{});$$->type="int";}
    | FLOAT {$$=createNode("Keyword","float",{}); $$->type="float";}
    | STR {$$=createNode("Keyword","str",{}); $$->type="string";}
    | BOOL {$$=createNode("Keyword","bool",{}); $$->type="boolean";}
    | NONE {$$=createNode("Keyword","None",{}); $$->type="none";}  
    | IDENTIFIER {$$=createNode("Identifier",*$1,{}); 
        if(curr->look_up(*$1)==NULL){
            yyerror("Class not declared");
        }
        
        
        
        $$->type="class_"+*$1;
        }
type: type1 {$$=$1;}
    | LIST LLIST type1 RLIST {
        Node *lst=createNode("Keyword","list",{});
        Node * ll=createNode("Delimiter","[",{});
        Node* rl=createNode("Delimiter","]",{});
        $$=createNode("type","t",{lst,ll,$3,rl});
        $$->type="list["+$3->type+"]";}
expr_stmt: testlist_star_expr expr_list {
    $$=createNode("expr_stmt","",{$1,$2}); 
    if($2->label == "Annassign") $1->sym->update_type($2->type);
    // $1->sym->printSym();
    // cout<<"hello\n";

    // cout<<$1->sym->type<<" re\n";
    // cout<<$2->type<<" re\n";
    string type=$1->sym->type;
    if($2->label!="Annassign"){
        if (curr->look_up($1->sym->lexeme)==NULL and $1->sym->lexeme!="print") {cout<<$1->sym->lexeme<<" "<<curr->st_category<<endl; yyerror("type_annotations not given");}
        else if ($1->sym->lexeme!="print") 
        { Symbol * sym=curr->look_up($1->sym->lexeme);
        type=sym->type;
        $1->sym->update_type(type);
        }// cout<<"type:"<<type<<endl;
    }
    // $1->sym->printSym();
    // cout<<"byebye\n";
    // cout<<"after notann\n";
    if($1->sym->type.substr(0,4)=="list"){
        size_t f=$1->sym->type.find("]");
        if(f!=string::npos){
            type=$1->sym->type.substr(5,f-5);
        }
    }
    // cout<<"after notlist"<<endl;
    for(auto &i:$2->Sym_list){
        //cout<<"ss";
        if (i==NULL) continue; 

        
        // cout<<"\nlll"<<i->lexeme<<" "<<i->type<<"er"<<endl;
        if (i->type=="id" && curr->look_up(i->lexeme)==NULL){
            yyerror("Not declared");
        }
        // cout<<i->type<<"  r\n";

        // cout<<$1->sym->type<<"  r\n";
        if(i->type!=type and i->type.substr(0,4)!="list" ) yyerror("Type Mismatch");
    }
    
    // cout<<"out\n";
    if($2->label == "Annassign") {
        $1->sym->is_decl=true;$1->sym->type=$2->type;
        // cout<<$1->sym->lexeme<<endl;
        // cout<<$2->type.substr(0,4)<<"leep\n"; 
        if($2->type.substr(0, 4) == "list" ){
            if(is_funccall){
                is_funccall=0;
                string a2="return_value";
                quad *q=new quad($1->sym->lexeme,"","","");
                q->make_code_from_return_val();
                $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                $$->code.push_back(q);
            }
            else{
                string op = "push_param";
                string sz=to_string(8*($2->Sym_list.size()));
                quad* q6 = new quad("", sz, op, "");
                q6->make_code_push_param();
                // $$->code.push_back(q6);

                string arg1 = "allocmem";
                op="call_func";
                quad* q3 = new quad("", arg1, op, "");
                q3->make_code_from_func_call();
                // $$->code.push_back(q3);

                string tar=string("_t")+to_string(temp_cnt);
                temp_cnt++;
                quad* q4 = new quad(tar, "", "", "");
                q4->make_code_from_return_val();
                // $$->code.push_back(q4);
            string ar1=$1->sym->lexeme;
            // cout<<"attribute "<<trailer_attr<<endl;
            if(trailer_attr!=""){
                
                ar1=trailer_attr;
                trailer_attr="";
            }
            // cout<<"leep "<<q->code<<endl;
            $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
            $$->code.push_back(q6);
            $$->code.push_back(q3);
            $$->code.push_back(q4);
            string ar2= string("_t")+to_string(temp_cnt-1);
            quad *q1=new quad(ar2,$2->Sym_list[0]->lexeme,"=","");
            q1->make_code_from_store();
            $$->code.push_back(q1);
            
            for(int i=1;i<$2->Sym_list.size();i++){
                string tar=string("_t")+to_string(temp_cnt);
                temp_cnt++;
                
                quad* q2 = new quad(tar, ar2, "+", to_string(i*8));
                q2->make_code_from_binary();
                $$->code.push_back(q2);
                
                quad* q3=new quad(tar,$2->Sym_list[i]->lexeme,"=","");
                q3->make_code_from_store();
                $$->code.push_back(q3);

                

            }
            quad *qw=new quad(ar1,ar2,"=","");
            qw->make_code_from_assignment();
            $$->code.push_back(qw);

            }
        }
        if(curr->st_category!='C' and curr->st_category!='M')
        curr->add_entry($1->sym);
        else if (curr->st_category=='M'){
            symbol_table_func* fs=(symbol_table_func *)curr;
            // cout<<$1->sym->lexeme<<" method\n";
            fs->add_entry($1->sym);
        }
        else{
            symbol_table_class* cls=(symbol_table_class *)curr;
            cls->attrs.push_back($1->sym);
        }
        }
    // else if (curr->st_category=='C')
    // else if (curr->st_category=='C'){cout<<$1->suym->lexeme<<end;l;}
    
    else if(curr->look_up($1->sym->lexeme)==NULL and $1->sym->lexeme!="print") {
        if(curr->st_category=='C'){
            symbol_table_class *cls=(symbol_table_class*)curr;
            // for(auto it:cls->attrs) cout<<it->lexeme<<"dddd\n";
        }
        yyerror("Type annotations not given");}
    
    if($2->label != "expr_list_empty" and $1->listchk != "list_ind" && $2->label != "Augassign" and $2->listchk != "list_ind"){
        if($2->type.substr(0,4)!="list"){
            string a2=$2->res;
            if(is_funccall){
                is_funccall=0;
                a2="return_value";
                quad *q=new quad($1->sym->lexeme,"","","");
                q->make_code_from_return_val();
                $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                $$->code.push_back(q);
            }
            else if(is_ctorcall){
                is_ctorcall=0;
                a2="return_value";
                string arg1 = string("_t")+to_string(temp_cnt-1);
                quad *q=new quad($1->sym->lexeme,arg1,"","");
                q->make_code_from_assignment();
                $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                $$->code.push_back(q);
                // $1->sym->self = arg1;
            }
            else{
            string ar1=$1->sym->lexeme;
            // cout<<$1->sym->lexeme<<" "<<$1->sym->is_attr<<endl;
            // cout<<$2->res<<" "<<$2->is_attr<<endl;
            if(trailer_attr!=""){
                ar1=trailer_attr;
                trailer_attr="";
            }
            // if(curr->st_category=='M'){
            //     symbol_table_func* fs=(symbol_table_func *)curr;
            //     // cout<<$1->sym->lexeme<<" method\n";
            //     if(fs->look_up($1->sym->lexeme)==NULL) fs->add_entry($1->sym);
            // }
            quad *q=new quad($1->sym->lexeme,$2->res,"=","");
            if($1->sym->is_attr == true) q->self_res = true;
            if($2->is_attr == true) q->self_arg1 = true;
            q->make_code_from_assignment();
            $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
            $$->code.push_back(q);
            }
        }
        // for(auto cd:$$->code) cout<<"final "<<cd->code<<endl;
    }
    // cout<<"islist"<<$1->listchk<<" he"<<$2->listchk<<endl;
    if($2->listchk == "list_ind"){
        // cout<<"listchk1\n";
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        string arg1 = $1->res;
        quad *q1=new quad(arg1,tar,"=","");
        q1->make_code_from_load();
        $$->code.insert($$->code.begin(),$1->code.begin(),$1->code.end());
        $$->code.insert($$->code.begin(),$2->code.begin(),$2->code.end());
        $$->code.push_back(q1);
    }
    if($1->listchk == "list_ind"){
        // cout<<"listchk1\n";
        string tar=string("_t")+to_string(temp_cnt);
        // temp_cnt++;
        // string tar=$2->res;
        string arg1 = $2->res;
        quad *q1=new quad(tar,arg1,"=","");
        q1->make_code_from_store();
        $$->code.insert($$->code.begin(),$1->code.begin(),$1->code.end());
        $$->code.insert($$->code.begin(),$2->code.begin(),$2->code.end());
        $$->code.push_back(q1);
    }   
    // if($2->listchk == "list_ind"){
    //     cout<<"listchk11\n";
    //     string tar='*'+string("_t")+to_string(temp_cnt);
    //     temp_cnt++;
    //     string arg1 = $2->res;
    //     quad *q1=new quad(tar,arg1,"=","");
    //     q1->make_code_from_assignment();
    //     // $$->code=$1->code;
    //     $$->code.push_back(q1);
    // } 
    
    if($2->label == "Augassign"){
        $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        string arg1=$1->res;
        string op=$2->op;
        string arg2=$2->res;
        // cout<<$1->sym->lexeme<<" "<<$1->sym->is_attr<<endl;
        // cout<<$2->res<<" "<<$2->is_attr<<endl;
        quad* q = new quad(tar, arg1, op, arg2);
        if($1->sym->is_attr) q->self_arg1 = true;
        if($2->is_attr) q->self_arg2 = true;
        q->make_code_from_binary();
        $$->code.push_back(q);
        // cout<<q->code<<endl;
        string res=$1->res;
        arg1=tar;
        quad* q1 = new quad(res, arg1, "", "");
        if($1->sym->is_attr) q1->self_res = true;
        q1->make_code_from_assignment();
        $$->code.push_back(q1);
        // cout<<q1->code<<endl;

    }
    if($2->label=="expr_list_empty") {
        $$->code=$1->code;
        if(is_funccall){
                is_funccall=0;
                
                // a2="return_value";
                quad *q=new quad("","","","");
                q->make_code_from_return_val();
                // $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
        // if($1->Sym_list[0]->lexeme!="print") 
        $$->code.push_back(q);
            }
    }
    // $1->sym->printSym();
    // cout<<"byebye1\n";
    $$->sym=$1->sym;
    }
expr_list: annassign {$$=$1;}
    | augassign testlist {$$=createNode("Augassign","",{$1,$2}); 
                            $$->code = $2->code;
                            $$->res = $2->resset[0];
                            $$->op = $1->value[0];
                            $$->is_attr = $2->is_attr;
                            $$->listchk = $2->listchk;

                        }
    | EQUALS testlist_star_expr eq_test{
        Node * eq=createNode("Equals","=",{});$$=createNode("expr_list","",{eq,$2,$3});
        $$->Sym_list = $2->Sym_list;
        $$->op="=";
        $$->code=$2->code;
        $$->is_attr = $2->sym->is_attr;
        $$->res=$2->res;
        $$->type=$2->type;
        $$->listchk = $3->listchk;
        } 
    | {$$=createNode("expr_list_empty","",{});}
eq_test: eq_test EQUALS testlist_star_expr {$$=$1; Node * eq=createNode("Equals","=",{});$$->children.push_back(eq);$$->children.push_back($3);}
        | {$$=createNode("eq_test", "", {});} 
annassign: COLON type annassign_a {
    Node * cl=createNode("colon",":",{});$$=createNode("Annassign","",{cl,$2,$3});
    $$->type=$2->type;
    $$->Sym_list=$3->Sym_list;
    $$->op="=";
    // cout<<"a"<<endl;
    $$->is_attr = $3->is_attr;
    // cout<<"b"<<endl;
    $$->res=$3->res;
    $$->code=$3->code;
    $$->listchk = $3->listchk;
    // cout<<$$->listchk<<"listck\n";
    //cout<<$2->type<<" tt"<<$3->type<<endl;
    //if($2->type!=$3->type) yyerror("type mismatch");

    //  for(auto cd:$$->code) cout<<"codeq10 "<<cd->code<<endl;
    // cout<<"done kk\n";
    }
annassign_a: EQUALS testlist_star_expr {Node * eq=createNode("Equals","=",{});$$=createNode("Annassign_a","",{eq,$2});$$->Sym_list=$2->Sym_list;
    $$->op="=";
    $$->res=$2->res;
    // cout<<"c"<<endl;
    // cout<<$2->listchk<<endl;
    if($2->sym) $$->is_attr = $2->sym->is_attr;
    else $$->is_attr = false;
    // cout<<"d"<<endl;
    $$->code=$2->code;
    $$->type=$2->type;
    $$->listchk = $2->listchk;
    // cout<<$$->listchk<<"listck\n";

    //  for(auto cd:$$->code) cout<<"codeq9 "<<cd->code<<endl;
    // cout<<"done1 "<< $$->res<<"kk\n";

}| {$$=createNode("Annassign_a","",{});}
testlist_star_expr: test_star comm_test_star COMMA {Node * cmma=createNode("comma",",",{});$$=createNode("testlist_star","",{$1,$2,cmma}); $$->sym = $1->sym; $$->Sym_list = $1->Sym_list;}
    | test_star comm_test_star {$$=createNode("Testlist_star","",{$1,$2});$$->sym = $1->sym; $$->Sym_list = $1->Sym_list;$$->code=$1->code;$$->res=$1->res;$$->type=$1->type;$$->listchk = $1->listchk;}
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
return_stmt: RETURN testlist_star_expr {
                                        Node *n11 = createNode("Keyword","return",{});
                                        $$=createNode("return_stmt","",{n11, $2});
                                        $$->code = $2->code;
                                        string arg1 = $2->res;
                                        // string op1="push_param";
                                        // quad* q1 = new quad("", arg1, op1, ""); 
                                        // q1->make_code_push_param();
                                        // $$->code.push_back(q1); 
                                        string op="return";
                                        quad* q = new quad("", arg1, op, "");
                                        q->self_arg1 = $2->sym->is_attr;
                                        q->make_code_from_return();
                                        $$->code.push_back(q);
                                        // cout<<"return_stmt"<<q->code<<endl;
                                        }
|            RETURN {$$=createNode("Keyword","return",{}); string op="return"; quad* q = new quad("", "", op, ""); q->make_code_from_return(); $$->code.push_back(q);}

global_stmt: GLOBAL IDENTIFIER comm_name {Node *n1 = createNode("Keyword","Global",{}); Node *n2 = createNode("IDENTIFIER",*$2,{}); $$=createNode("global_stmt","",{n1, n2, $3});}
comm_name:comm_name COMMA IDENTIFIER {$$=$1;Node *n1 = createNode("Delimiter",",",{}); Node *n2 = createNode("IDENTIFIER",*$3,{}); $$->children.push_back(n1);$$->children.push_back(n2);} 
        | {$$=createNode("comm_name", "", {});}
nonlocal_stmt: NONLOCAL IDENTIFIER comm_name {Node *n1 = createNode("Nonlocal","nonlocal",{}); Node *n2 = createNode("IDENTIFIER",*$2,{}); $$=createNode("nonlocal_stmt","",{n1, n2, $3});}
assert_stmt: ASSERT test comma_test_maybe {Node *n1 = createNode("Keyword","Assert",{});  $$=createNode("Assert_stmt","",{n1, $2, $3});}
comma_test_maybe: COMMA test {Node *n1=createNode("Delimiter",",",{}); $$=createNode("comma_testmaybe","",{n1,$2});}| {$$ = createNode("comma_test_maybe",",",{});}

compound_stmt: if_stmt {$$=$1;}| while_stmt{$$=$1;} | for_stmt{$$=$1;} | funcdef{$$=$1;} | classdef{$$=$1;} | async_stmt{$$=$1;}
async_stmt: ASYNC funcdef {Node *n1=createNode("Keyword","Async",{}); $$=createNode("async_stmt","",{n1,$2});}
    | ASYNC for_stmt {Node *n1=createNode("Keyword","Async",{}); $$=createNode("async_stmt","",{n1,$2});}


if_stmt: IF {symbol_table * if_block=new symbol_table("if_cond");curr->add_scope(if_block);curr=if_block;} test {
    // cout<<$3->op<<"operator\n";
    if ($3->op!=""){
        if($3->Sym_list[0]->lexeme=="__name__"){
            // cout<<"mainnn"<<$3->Sym_list[1]->lexeme<<endl;
            if ($3->Sym_list[1]->lexeme!="\"__main__\"")
             yyerror("Only main allowed");
         }
        else{string type=$3->Sym_list[0]->type;
        for(auto x:$3->Sym_list){
            if (type!=x->type)
                yyerror("Type does not match between operands");
        }}
    }
    // for(auto &x:$3->Sym_list){
    //     // x->printSym();
    //     // cout<<x->type<<"if\n";
    // }
}COLON suite elif_namedexprtest_colon_suite else_colon_suite_maybe {
    Node *n1=createNode("KEYWORD","if",{});
    Node *n2=createNode("Delimiter",":",{});
    $$=createNode("If_stmt","",{n1,$3,n2,$6,$7,$8});
    //symbol_table * if_block= new symbol_table("if_cond");
    
    curr=curr->parent;
    $$->code=$3->code;
    string op="if_false";
    string arg1=$3->res;
    string arg2="j+"+to_string($6->code.size()+2);
    quad* q = new quad("",arg1,op,arg2);
    q->make_code_from_conditional();
    $$->code.push_back(q);
    ircode.push_back(q);
    $$->code.insert($$->code.end(), $6->code.begin(), $6->code.end());

    op="goto";
    arg1="j+"+to_string($8->code.size()+1);
    quad* q1=new quad("",arg1,op,"");
    q1->make_code_from_goto();
    $$->code.push_back(q1);
    ircode.push_back(q1);
    $$->code.insert($$->code.end(), $8->code.begin(), $8->code.end());


    //int cnt=0;
    //for(auto line:$3->code) cnt++;
    //for(auto line:$5->code) cnt++;
    
    //q->op="if_false";
    //q->arg1=$3->res;
    //q->rel_jump = cnt;
    
    // cout<<"qcode "<<q->code<<endl;
    // cout<<"q1code "<<q1->code<<endl;
    //$$->code.push_back(q); 
    // for(auto qq:$$->code) cout<<"cond "<<qq->code<<endl;
    
    }
while_stmt: WHILE {symbol_table * while_block=new symbol_table("while");curr->add_scope(while_block);curr=while_block;} test COLON suite else_colon_suite_maybe {
    Node *n1=createNode("Keyword","while",{});
    Node *n2=createNode("Delimiter",":",{});
    $$=createNode("while","",{n1,$3,n2,$5,$6}); 
    curr=curr->parent;
    $$->code=$3->code;
    string op="if_false";
    string arg1=$3->res;
    string arg2="j+"+to_string($5->code.size()+2);
    quad* q = new quad("",arg1,op,arg2);
    q->make_code_from_conditional();
    $$->code.push_back(q);
    ircode.push_back(q);
    $$->code.insert($$->code.end(), $5->code.begin(), $5->code.end());

    op="goto";
    arg1="j-"+to_string($5->code.size()+2);
    quad* q1=new quad("",arg1,op,"");
    q1->make_code_from_goto();
    $$->code.push_back(q1);
    ircode.push_back(q1);
    // for(auto qq:$$->code) cout<<"cond while"<<qq->code<<endl;
    }
for_stmt: FOR {symbol_table * for_block=new symbol_table("for");curr->add_scope(for_block);curr=for_block;} exprlist IN RANGE LPAREN testlist RPAREN COLON suite else_colon_suite_maybe {
    Node* n1=createNode("Keyword","For",{});Node* n2=createNode("Keyword","In",{});
    Node* n3=createNode("Keyword","Range",{});Node* n4=createNode("Lparen","(",{});
    Node* n5=createNode("rparen",")",{});Node* n6=createNode("Delimiter",":",{});
    $$=createNode("for","",{n1,$3,n2,n3,n4,$7,n5,n6,$10,$11});
    curr=curr->parent;
    $$->code = $3->code;
    $$->code.insert($$->code.end(), $7->code.begin(), $7->code.end());
    for(auto it: $3->resset){
        // cout<<"ressetsize "<<$7->resset.size()<<" "<<$7->resset[0]<<" "<<$7->resset[1]<<" "<<$7->resset[2]<<" "<<$7->resset[3]<<endl;
        string arg1 = it;
        string op = "<";
        string argj = "j+"+to_string($10->code.size()+4);
        if($7->resset.size() == 1){
            string arg2 = $7->resset[0];
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q = new quad(tar, arg1, op, arg2);
            q->make_code_from_binary();
            $$->code.push_back(q);
            ircode.push_back(q);
            string op1="if_false";
            quad* q1 = new quad("", tar, op1, argj);
            q1->make_code_from_conditional();
            $$->code.push_back(q1);
            ircode.push_back(q1);
        }
        else if($7->resset.size() == 2 || $7->resset.size() == 3 || $7->resset.size() == 4){
            string arg10 = $7->resset[0];
            quad* q10 = new quad(it, arg10, "", "");
            q10->make_code_from_assignment();
            $$->code.push_back(q10);
            ircode.push_back(q10);
            string arg2 = $7->resset[1];
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q = new quad(tar, arg1, op, arg2);
            q->make_code_from_binary();
            $$->code.push_back(q);
            ircode.push_back(q);
            string op1="if_false";
            quad* q1 = new quad("", tar, op1, argj);
            q1->make_code_from_conditional();
            $$->code.push_back(q1);
            ircode.push_back(q1);
        }
            // string arg2="j+"+to_string($10->code.size()+2);
    // quad* q = new quad("",arg1,op,arg2);
    // q->make_code_from_conditional();
    }
    $$->code.insert($$->code.end(), $10->code.begin(), $10->code.end());
    if($7->resset.size() == 1 || $7->resset.size() == 2){
        for(auto itr: $3->resset){
            string ar1 = itr;
            string opr = "+";
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q2 = new quad(tar, ar1, opr, "1");
            q2->make_code_from_binary();
            $$->code.push_back(q2);
            ircode.push_back(q2);
            quad* q3 = new quad(itr, tar, "", "");
            q3->make_code_from_assignment();
            $$->code.push_back(q3);
            ircode.push_back(q3);
        }
    }
    else if($7->resset.size() == 3 || $7->resset.size() == 4){
        for(auto itr: $3->resset){
            string ar20 = $7->resset[3];
            string ar1 = itr;
            string opr = "+";
            string tar=string("_t")+to_string(temp_cnt);
            temp_cnt++;
            quad* q2 = new quad(tar, ar1, opr, ar20);
            q2->make_code_from_binary();
            $$->code.push_back(q2);
            ircode.push_back(q2);
            quad* q3 = new quad(itr, tar, "", "");
            q3->make_code_from_assignment();
            $$->code.push_back(q3);
            ircode.push_back(q3);
        }
    }
    string opb="goto";
    string arg1b="j-"+to_string($10->code.size()+4);
    quad* qb=new quad("",arg1b,opb,"");
    qb->make_code_from_goto();
    $$->code.push_back(qb);
    }
else_colon_suite_maybe: ELSE COLON suite {Node* n1=createNode("Keyword","Else",{});Node* n2=createNode("Delimiter",":",{});$$=createNode("else","",{n1,n2,$3});$$->code=$3->code;}| {$$=createNode("else_colon_suite_maybe","",{});}

elif_namedexprtest_colon_suite: elif_namedexprtest_colon_suite ELIF test COLON suite{$$=$1;Node* n1=createNode("Keyword","Elif",{});Node* n2=createNode("Delimiter",":",{});$$->children.push_back(n1);$$->children.push_back($3);$$->children.push_back(n2);$$->children.push_back($5);} 
                            | {$$=createNode("elif_namedexprtest_colon_suite", "", {});}


suite: simple_stmt {$$=$1;} 
|     NEWLINE INDENT  stmt_morethanone DEDENT {
    Node * n1=createNode("Newline","nl",{});Node * n2=createNode("Indent","Indent",{});Node * n3=createNode("Dedent","Dedent",{});
    $$=createNode("suite","",{n1,n2,$3,n3});$$->code=$3->code;
}

stmt_morethanone: stmt_morethanone stmt {
    // $$=$1;
    // cout<<"abort-2\n";
$$=createNode("stmt_more","",{$1}); $$->code = $1->code;for(auto ch:$1->children) $$->children.push_back(ch);
$$->children.push_back($2);$$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());} | stmt{$$=createNode("stmt_more","",{$1}); $$->code = $1->code;}

test: or_test if_ortest_else_test_maybe {$$=createNode("test","",{$1,$2}); $$->sym = $1->sym; $$->Sym_list = $1->Sym_list;
                                        $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end());
                                $$->res=$1->res;
                                $$->code=$1->code;
                                $$->listchk = $1->listchk;
                                $$->last=$1->last;
                                if($2->is_empty) $$->op=$1->op;
                                // cout<<$1->op<<"oper1\n";
                                string op=$2->op;
                                string rhs=$2->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                $$->type=$1->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,$1->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                    $$->code.push_back(q);
                                    ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                    $$->res=tar;
                                }
                                //  for(auto cd:$$->code) cout<<"codeq8 "<<cd->code<<endl;
    // cout<<"done2 "<< $$->res<<"kk\n";
}
if_ortest_else_test_maybe: IF or_test ELSE test {
    Node * n1=createNode("Keyword","if",{});Node * n2=createNode("Keyword","else",{});
    $$=createNode("if_or_else","",{n1,$2,n2,$4});
}| {$$ = createNode("if_ortest_else_test_maybe","",{});$$->is_empty=true;}
// {cout<<"not1\n";}
or_test: and_test or_andtest {$$=createNode("or_test","",{$1,$2}); $$->sym = $1->sym; $$->Sym_list = $1->Sym_list;
                                $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end());
                                $$->res=$1->res;
                                $$->code=$1->code;
                                $$->listchk = $1->listchk;
                                $$->last=$1->last;
                                if($2->is_empty) $$->op=$1->op;
                                // cout<<$2->is_empty<<" "<<$1->op<<"oper2\n";
                                string op=$2->op;
                                string rhs=$2->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                $$->type=$1->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,$1->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                    $$->code.push_back(q);
                                    ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                    $$->res=tar;
                                }
                                //  for(auto cd:$$->code) cout<<"codeq7 "<<cd->code<<endl;
    // cout<<"done kk\n";
}
or_andtest: or_andtest OR and_test {$$=createNode("or_andtest", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:$1->children) $$->children.push_back(ch);
                                                        $$->last=$1->last;
                                                        $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        $$->is_empty=false;Node * n1=createNode("Keyword","and",{});
                                                        $$->children.push_back(n1);
                                                        $$->children.push_back($3); 
                                                        $$->Sym_list.insert($$->Sym_list.end(), $3->Sym_list.begin(), $3->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        $$->type=$3->type;
                                                        if(!($1->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            $$->code=$1->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            $$->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            $$->op="or";
                                                            quad* q = new quad(res, $1->res, "or", $3->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            $$->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            $$->op = "or";
                                                            $$->res = $3->res;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }}
    | {$$=createNode("or_andtest", "", {});$$->is_empty=true;} 
// {cout<<"not2\n";}
and_test: not_test and_nottest {
                                $$=createNode("and_test","",{$1,$2}); $$->sym = $1->sym;
                                $$->Sym_list = $1->Sym_list;
                                $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end());
                                $$->res=$1->res;
                                $$->code=$1->code;
                                $$->listchk = $1->listchk;
                                $$->last=$1->last;
                                if($2->is_empty) $$->op=$1->op;
                                // cout<<$1->op<<"oper3\n";
                                string op=$2->op;
                                string rhs=$2->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                $$->type=$1->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,$1->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                    $$->code.push_back(q);
                                    ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                    $$->res=tar;
                                }

                                //  for(auto cd:$$->code) cout<<"codeq6 "<<cd->code<<endl;
    // cout<<"done kk\n";
                                }
and_nottest: and_nottest AND not_test {$$=createNode("and_nottest", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:$1->children) $$->children.push_back(ch);
                                                        $$->last=$1->last;
                                                        $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        $$->is_empty=false;Node * n1=createNode("Keyword","and",{});
                                                        $$->children.push_back(n1);
                                                        $$->children.push_back($3); 
                                                        $$->Sym_list.insert($$->Sym_list.end(), $3->Sym_list.begin(), $3->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        $$->type=$3->type;
                                                        if(!($1->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            $$->code=$1->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            $$->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            $$->op="and";
                                                            quad* q = new quad(res, $1->res, "and", $3->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            $$->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            $$->op = "and";
                                                            $$->res = $3->res;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }}
    | {$$=createNode("and_nottest", "", {});
     $$->is_empty=true;}
// {cout<<"not3\n";}
not_test: NOT not_test{$$=createNode("Keyword","not",{}); $$->children.push_back($2);} | comparison {$$=$1;}
comparison: expr comp_op_expr {
                                $$=createNode("comp","",{$1,$2}); $$->sym = $1->sym; $$->Sym_list = $1->Sym_list;
                                $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end());
                                $$->res=$1->res;
                                $$->code=$1->code;
                                $$->listchk = $1->listchk;
                                $$->last=$1->last;
                                $$->op=$2->op;
                                string op=$2->op;
                                string rhs=$2->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                $$->type=$1->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,$1->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                    $$->code.push_back(q);
                                    ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                    $$->res=tar;
                                }
                                //  for(auto cd:$$->code) cout<<"codeq5 "<<cd->code<<endl;
    // cout<<"done kk\n";
                                }
// {cout<<"not5\n";} 
comp_op_expr: comp_op_expr comp_op expr {
                                                        //Node * temp=$1;$$=$1;
                                                        $$=createNode("comp_op_expr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:$1->children) $$->children.push_back(ch);
                                                        $$->last=$1->last;
                                                        $$->Sym_list=$1->Sym_list;
                                                        // $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        $$->is_empty=false;$$->children.push_back($2);
                                                        $$->children.push_back($3); 
                                                        $$->Sym_list.insert($$->Sym_list.end(), $3->Sym_list.begin(), $3->Sym_list.end());
                                                        // cout<<"is "<<$2->value<<endl;
                                                        $$->type=$3->type;
                                                        if(!($1->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            $$->code=$1->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            $$->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            $$->op=$2->value;
                                                            quad* q = new quad(res, $1->res, $2->value, $3->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            $$->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        } 
                                                        else{
                                                            // cout<<$1->is_empty<<"empty\n";
                                                            $$->op = $2->value;
                                                            $$->res = $3->res;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }
                                                        } 
            | {$$=createNode("comp_op_expr", "", {}); $$->is_empty=true;}
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

star_expr: TIMES expr {Node *n1=createNode("Operator","*",{});$$=createNode("star_expr","",{n1,$2}); $$->Sym_list = $2->Sym_list;}
expr: xor_expr bitor_xorexpr {
                                $$=createNode("expr","",{$1,$2}); $$->sym = $1->sym; $$->Sym_list = $1->Sym_list;
                                $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end());
                                $$->res=$1->res;
                                $$->code=$1->code;
                                $$->listchk = $1->listchk;
                                $$->last=$1->last;
                                string op=$2->op;
                                string rhs=$2->res;
                                // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                $$->type=$1->type;
                                if (op!=""){
                                    string tar=string("_t")+to_string(temp_cnt);
                                    temp_cnt++;
                                    // cout<<"tar "<<tar<<endl;
                                    quad *q=new quad(tar,$1->res,op,rhs);
                                    q->make_code_from_binary();
                                    // cout<<"qqqq "<<q->code<<endl;
                                    $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                    $$->code.push_back(q);
                                    ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                    $$->res=tar;
                                }
                                //  for(auto cd:$$->code) cout<<"codeq4 "<<cd->code<<endl;
    // cout<<"done3 "<< $$->res<<"kk\n";
                                }
bitor_xorexpr: bitor_xorexpr BIT_OR xor_expr {$$=createNode("bitxor_andexpr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:$1->children) $$->children.push_back(ch);
                                                        $$->last=$1->last;
                                                        $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        $$->is_empty=false;Node * n1=createNode("Bit_op","|",{});
                                                        $$->children.push_back(n1);
                                                        $$->children.push_back($3); 
                                                        $$->Sym_list.insert($$->Sym_list.end(), $3->Sym_list.begin(), $3->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        $$->type=$3->type;
                                                        if(!($1->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            $$->code=$1->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            $$->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            $$->op="|";
                                                            quad* q = new quad(res, $1->res, "|", $3->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            $$->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            $$->op = "|";
                                                            $$->res = $3->res;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }
                                                        }
    | {$$=createNode("bitor_xorexpr", "", {}); $$->is_empty=true;}
xor_expr: and_expr bitxor_andexpr {$$=createNode("expr","",{$1,$2}); $$->sym = $1->sym; 
                                    $$->Sym_list = $1->Sym_list;
                                    $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end());
                                    $$->res=$1->res;
                                    $$->code=$1->code;
                                    $$->listchk = $1->listchk;
                                    $$->last=$1->last;
                                    string op=$2->op;
                                    string rhs=$2->res;
                                    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
                                    $$->type=$1->type;
                                    if (op!=""){
                                        string tar=string("_t")+to_string(temp_cnt);
                                        temp_cnt++;
                                        // cout<<"tar "<<tar<<endl;
                                        quad *q=new quad(tar,$1->res,op,rhs);
                                        q->make_code_from_binary();
                                        // cout<<"qqqq "<<q->code<<endl;
                                        $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                        $$->code.push_back(q);
                                        ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                        $$->res=tar;
                                    }
                                    //  for(auto cd:$$->code) cout<<"codeq3 "<<cd->code<<endl;
    // cout<<"done kk\n";
                                    }
bitxor_andexpr: bitxor_andexpr BIT_XOR and_expr {$$=createNode("bitxor_andexpr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:$1->children) $$->children.push_back(ch);
                                                        $$->last=$1->last;
                                                        $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        $$->is_empty=false;Node * n1=createNode("Bit_op","^",{});
                                                        $$->children.push_back(n1);
                                                        $$->children.push_back($3); 
                                                        $$->Sym_list.insert($$->Sym_list.end(), $3->Sym_list.begin(), $3->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        $$->type=$3->type;
                                                        if(!($1->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            $$->code=$1->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            $$->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            $$->op="^";
                                                            quad* q = new quad(res, $1->res, "^", $3->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            $$->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            $$->op = "^";
                                                            $$->res = $3->res;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }
                                                        }
    | {$$=createNode("bitxor_andexpr", "", {}); $$->is_empty=true;}
and_expr: shift_expr bitand_shiftexpr {
    $$=createNode("expr","",{$1,$2}); $$->sym = $1->sym; 
    $$->Sym_list = $1->Sym_list;
    $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end());
    $$->res=$1->res;
    $$->listchk = $1->listchk;
    $$->code=$1->code;
    $$->last=$1->last;

    string op=$2->op;
    string rhs=$2->res;
    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
    $$->type=$1->type;
    if (op!=""){
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        // cout<<"tar "<<tar<<endl;
        quad *q=new quad(tar,$1->res,op,rhs);
        q->make_code_from_binary();
        // cout<<"qqqq "<<q->code<<endl;
        $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
        $$->code.push_back(q);
        ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
        $$->res=tar;
    } 
    //  for(auto cd:$$->code) cout<<"codeq2 "<<cd->code<<endl;
    // cout<<"done kk\n";
    }
bitand_shiftexpr: bitand_shiftexpr BIT_AND shift_expr {$$=createNode("bitand_shiftexpr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:$1->children) $$->children.push_back(ch);
                                                        $$->last=$1->last;
                                                        $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        $$->is_empty=false;Node * n1=createNode("Bit_op","&",{});
                                                        $$->children.push_back(n1);
                                                        $$->children.push_back($3); 
                                                        $$->Sym_list.insert($$->Sym_list.end(), $3->Sym_list.begin(), $3->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        $$->type=$3->type;
                                                        if(!($1->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            $$->code=$1->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            $$->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            $$->op="&";
                                                            quad* q = new quad(res, $1->res, "&", $3->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            $$->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            $$->op = "&";
                                                            $$->res = $3->res;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }
                                                        }
    | {$$=createNode("bitand_shiftexpr", "", {}); $$->is_empty=true;}
shift_expr: arith_expr lorrshift_arithexpr {
    $$=createNode("shift_expr","",{$1,$2}); 
    $$->sym = $1->sym; $$->Sym_list = $1->Sym_list; 
    $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end());
    $$->res=$1->res;
    $$->code=$1->code;
    $$->listchk = $1->listchk;
    $$->type=$1->type;
    $$->last=$1->last;

    string op=$2->op;
    string rhs=$2->res;
    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
    if (op!=""){
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        // cout<<"tar "<<tar<<endl;
        quad *q=new quad(tar,$1->res,op,rhs);
        q->make_code_from_binary();
        // cout<<"qqqq "<<q->code<<endl;
        $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
        $$->code.push_back(q);
        ircode.push_back(q);
        $$->last=ircode.size()-1;
        $$->res=tar;
    }
    //  for(auto cd:$$->code) cout<<"codeq1 "<<cd->code<<endl;
    // cout<<"done kk\n";
    }

lorrshift_arithexpr: lorrshift_arithexpr lshift_or_rshift arith_expr {
                                                        $$=createNode("lorrshift_arithexpr", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:$1->children) $$->children.push_back(ch);
                                                        $$->last=$1->last;
                                                        $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        $$->is_empty=false;$$->children.push_back($2);
                                                        $$->children.push_back($3); 
                                                        $$->Sym_list.insert($$->Sym_list.end(), $3->Sym_list.begin(), $3->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        $$->type=$3->type;
                                                        if(!($1->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            $$->code=$1->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            $$->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            $$->op=$2->value;
                                                            quad* q = new quad(res, $1->res, $2->value, $3->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            $$->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            $$->op = $2->value;
                                                            $$->res = $3->res;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }
                                                        }
    
    
    
    
    
    | {$$=createNode("lorrshift_arithexpr", "", {});$$->is_empty=true;}
lshift_or_rshift: BIT_LSHIFT {$$=createNode("Bit_left_shift","<<",{});} | BIT_RSHIFT {$$=createNode("Bit_right_shift",">>",{});}
arith_expr: term plusorminus_term {
    $$=createNode("arith_expr","",{$1,$2}); 
    $$->sym = $1->sym; $$->Sym_list = $1->Sym_list; 
    $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end());
    $$->res=$1->res;
    $$->code=$1->code;
    $$->listchk = $1->listchk;
    $$->type=$1->type;
    $$->last=$1->last;
    string op=$2->op;
    string rhs=$2->res;
    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
    if (op!=""){
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        // cout<<"tar "<<tar<<endl;
        quad *q=new quad(tar,$1->res,op,rhs);
        q->make_code_from_binary();
        // cout<<"qqqq "<<q->code<<endl;
        $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
        $$->code.push_back(q);
        ircode.push_back(q);
        $$->last=ircode.size()-1;
        $$->res=tar;
    }
    
    //cout<<"code of "<<($$->code)<<"\n";
    // for(auto cd:$$->code) cout<<"codeq "<<cd->code<<endl;
    // cout<<"done kk\n";
    }

plusorminus_term: plusorminus_term plus_or_minus term  {
                                                        //Node * temp=$1;$$=$1;
                                                        $$=createNode("plusorminus_term", "", {});
                                                        //$$->children.push_back($1);
                                                        for(auto ch:$1->children) $$->children.push_back(ch);
                                                        $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        $$->is_empty=false;$$->children.push_back($2);
                                                        $$->children.push_back($3); 
                                                        $$->last=$1->last;
                                                        $$->Sym_list.insert($$->Sym_list.end(), $3->Sym_list.begin(), $3->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        $$->type=$3->type;
                                                        if(!($1->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            $$->code=$1->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            $$->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            $$->op=$2->value;
                                                            quad* q = new quad(res, $1->res, $2->value, $3->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            $$->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        } 
                                                        else{
                                                            // cout<<"empty\n";
                                                            $$->op = $2->value;
                                                            $$->res = $3->res;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }
                                                        } 
                | {$$=createNode("plusorminus_term", "", {});$$->is_empty=true;}
plus_or_minus: PLUS {$$=createNode("Operator","+",{});}| MINUS {$$=createNode("Operator","-",{});}
term: factor timedivmod_factor {
    $$=createNode("term","",{$1,$2});
    $$->sym=$1->sym; 
    $$->Sym_list = $1->Sym_list; 
    $$->Sym_list.insert($$->Sym_list.end(), $2->Sym_list.begin(), $2->Sym_list.end()); 
    if($$->sym) 
    {string ar1=$$->sym->lexeme;
            // cout<<"attribute "<<trailer_attr<<endl;
            if(trailer_attr!=""){
                
                ar1=trailer_attr;
                trailer_attr="";
            }
            $$->res=ar1;
    }
    $$->type=$1->type;
    $$->code=$1->code;
    $$->listchk = $1->listchk;
    $$->last=$1->last;
    string op=$2->op;
    string rhs=$2->res;
    // cout<<"oper "<<op<<" rhs"<<rhs<<endl;
    if (op!=""){
        string tar=string("_t")+to_string(temp_cnt);
        temp_cnt++;
        // cout<<"tar "<<tar<<endl;
        quad *q=new quad(tar,$1->res,op,rhs);
        q->make_code_from_binary();
        // cout<<"qqqq "<<q->code<<endl;
        $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
        $$->code.push_back(q);
        ircode.push_back(q);
        $$->last=ircode.size()-1;
        $$->res=tar;
    }
    
    //cout<<"code of "<<($$->code)<<"\n";
    // for(auto cd:$$->code) cout<<"codeqmul "<<cd->code<<endl;
    // cout<<"donea kk\n";
    }
timedivmod_factor: timedivmod_factor timedivmod factor {
                                                        $$=createNode("timedivmod_factor", "", {});
                                                        //$$->children.push_back($1);
                                                        // cout<<"donerr1\n";
                                                        for(auto ch:$1->children) $$->children.push_back(ch);
                                                        $$->last=$1->last;
                                                        $$->Sym_list.insert($$->Sym_list.end(), $1->Sym_list.begin(), $1->Sym_list.end());
                                                        $$->is_empty=false;$$->children.push_back($2);
                                                        $$->children.push_back($3); 
                                                        $$->Sym_list.insert($$->Sym_list.end(), $3->Sym_list.begin(), $3->Sym_list.end());
                                                        // cout<<"is "<<$1->is_empty<<endl;
                                                        $$->type=$3->type;
                                                        // $$->listchk = $3->listchk;
                                                        if(!($1->is_empty)){
                                                            // cout<<"not empty "<<$1->res<<endl;
                                                            $$->code=$1->code; 
                                                            string res = string("_t") + to_string(temp_cnt); 
                                                            temp_cnt++; 
                                                            $$->res = res; 
                                                            // cout<<"not empty "<<$1->res<<" "<<$$->res<<endl;
                                                            $$->op=$2->value;
                                                            quad* q = new quad(res, $1->res, $2->value, $3->res); 
                                                            q->make_code_from_binary(); 
                                                            // cout<<"qcode "<<q->code<<endl;
                                                            $$->code.push_back(q); 
                                                            ircode.push_back(q);
                                                            $$->last=ircode.size()-1;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }
                                                        else{
                                                            // cout<<"empty\n";
                                                            $$->op = $2->value;
                                                            $$->res = $3->res;
                                                            $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                                        }
                                                        }
                    | {$$=createNode("timedivmod_factor", "", {});$$->is_empty=true;}
timedivmod: TIMES{$$=createNode("Operator","*",{});}|DIVIDEDBY{$$=createNode("Operator","/",{});}|MODULO{$$=createNode("Operator","%",{});}|MOD {$$=createNode("Operator","//",{});}
factor: plusminusnot factor {$$=$1; $$->children.push_back($2); $$->Sym_list = $2->Sym_list;} 
        | power {$$=$1;
        // cout<<"llpppoo\n";
        // for(auto it:$$->code)
        // cout<<it->code<<endl;
        }
plusminusnot: PLUS {$$=createNode("Operator","+",{});}| MINUS {$$=createNode("Operator","-",{});}| BIT_NOT{$$=createNode("Operator","~",{});}
power: atom_expr pow_factor_maybe {$$=createNode("power","",{$1,$2});$$->sym=$1->sym;if($$->sym) $$->res=$$->sym->lexeme;$$->type=$1->type; $$->Sym_list = $1->Sym_list; if($1->sym) $$->Sym_list.push_back($1->sym); $$->code = $1->code;$$->listchk = $1->listchk;}
pow_factor_maybe: POW factor {Node *n1=createNode("Operator","**",{});$$=createNode("pow_maybe","",{n1,$2}); $$->Sym_list.push_back($2->sym);} | {$$=createNode("pow_maybe","",{});}


atom_expr: AWAIT atom trailer {Node *n1=createNode("KEYWORD","AWAIT",{});$$=createNode("atom_expr","",{n1,$2});} 
| atom trailer {
    // cout<<"atom_expr "<<$1->sym->lexeme<<endl;
    $$=createNode("atom_expr","",{$1,$2});
    $$->type=$1->type;
    if($1->value == "self") {$$->sym=$2->sym;$$->sym->is_attr=true;}
    
    else{
        // cout<<"else atom trailer\n";
        $$->sym=$1->sym;
        $$->Sym_list=$1->Sym_list;

        if($2->label=="trailer_arglist"){
            // cout<<"Called args\n";
            if(curr->look_up($1->sym->lexeme)==NULL and $1->sym->lexeme!="print") yyerror("Class/Func not defined");
            else if($1->sym->lexeme=="print"){
                $$->code=$2->code;
                is_funccall=1;
                bool is_string=false;
                if($2->Sym_list.size()==1 and $2->Sym_list[0]->type=="string"){
                    string arg1=$2->Sym_list[0]->lexeme;
                    quad *qs= new quad("",arg1,"","");
                    qs->make_code_print_string();
                    $$->code.push_back(qs);
                    is_print_string=0;
                }
                
                else{
                string arg1 = "print";
                string op="call_func";
                quad* q = new quad("", arg1, op, "");
                q->make_code_from_func_call();
                // cout<<q->code<<"\n";
                $$->code.push_back(q);}
                
                // ircode.push_back(q);
            }
            else{
                // cout<<"Called func\n";
                
                string ag1 = "";
                if($1->sym->is_func){
                    symbol_table_func * funcst=ogroot->look_up_func($1->sym->lexeme);
                    if(funcst->params.size()!=$2->Sym_list.size()) yyerror("Incorrect no of params");
                    for(int i=0;i<funcst->params.size();i++){
                        if(funcst->params[i]->type!=$2->Sym_list[i]->type) yyerror("Type mismatch of params");
                    }
                is_funccall=1;
                $$->code=$2->code;
                ag1='+'+to_string(8*funcst->params.size());
                quad* q1 = new quad("", ag1, "", "");
                q1->make_code_stack_pointer();
                // cout<<q1->code<<"\n";
                // $$->code.push_back(q1);

                string arg1 = $1->sym->lexeme;
                string op="call_func";
                quad* q = new quad("", arg1, op, "");
                q->make_code_from_func_call();
                // cout<<q->code<<"\n";
                $$->code.push_back(q);
                ircode.push_back(q);

                ag1='-'+to_string(8*funcst->params.size());
                quad* q2 = new quad("", ag1, "", "");
                // q2->make_code_stack_pointer();
                // cout<<q2->code<<"\n";
                // $$->code.push_back(q2);
                }

                else if($1->sym->is_class) {
                    symbol_table_class * clst=ogroot->look_up_class($1->sym->lexeme);
                    if(clst->params.size()!=($2->Sym_list.size())) yyerror("Incorrect no of params");
                    for(int i=0;i<clst->params.size();i++){
                        if(clst->params[i]->type!=$2->Sym_list[i]->type) yyerror("Type mismatch of params");
                    }
                    is_ctorcall = 1;
                    $$->code=$2->code;
                    ag1='+' + to_string(8*clst->params.size());
                quad* q1 = new quad("", ag1, "", "");
                // q1->make_code_stack_pointer();
                // $$->code.push_back(q1);

                string op = "push_param";
                string sz=to_string(8*(clst->attrs.size()));
                quad* q6 = new quad("", sz, op, "");
                q6->make_code_push_param();
                $$->code.push_back(q6);

                string arg1 = "allocmem";
                op="call_func";
                quad* q3 = new quad("", arg1, op, "");
                q3->make_code_from_func_call();
                $$->code.push_back(q3);

                string tar=string("_t")+to_string(temp_cnt);
                temp_cnt++;
                quad* q4 = new quad(tar, "", "", "");
                q4->make_code_from_return_val();
                $$->code.push_back(q4);

                op = "push_param";
                quad* q5 = new quad("", tar, op, "");
                q5->make_code_push_param();
                $$->code.push_back(q5);
                // $$->sym->lexeme = tar;

                arg1 = $1->sym->lexeme + '.' + "__init__";
                op="call_func";
                quad* q = new quad("", arg1, op, "");
                q->make_code_from_func_call();
                $$->code.push_back(q);
                ircode.push_back(q);
                ag1='-'+to_string(8*clst->params.size());
                quad* q2 = new quad("", ag1, "", "");
                // q2->make_code_stack_pointer();
                // $$->code.push_back(q2);
                }
            }
            // quad* q1 = new quad("", ag1, "", "");
            // q1->make_code_stack_pointer();
            // $$->code.push_back(q1);
        }
        else if($2->label=="trailer_method"){
            // cout<<"problem"<<endl;
            string class_name=$1->type.substr(6,$1->type.size()-1);
            // cout<<class_name<<"taraa";
            if(ogroot->look_up_class(class_name)==NULL){
                yyerror("class not declared");
            }
            symbol_table_class * cls=ogroot->look_up_class(class_name);
            if(cls->look_upfunc($2->sym->lexeme)==NULL) yyerror("Member Function not defined");
            symbol_table_func *fun=cls->look_upfunc($2->sym->lexeme);

            symbol_table_class * cls2=cls;

            if(cls2->parent_name != "global") cls2=ogroot->look_up_class(cls2->parent_name);
            // for(auto x1:fun->params) cout<<"ddfff "<<x1->lexeme<<" pp "<<x1->type<<endl;
            if($2->Sym_list.size()!=(fun->params.size()-1)) yyerror("Params size mismatch");
            else{
            for(int i=0;i<fun->params.size()-1;i++){
                    // cout<<"SSDDDD "<<fun->params[i+1]->type<<" tt"<<$2->Sym_list[i]->type<<endl;
                    if(fun->params[i+1]->type!=$2->Sym_list[i]->type) yyerror("Type mismatch of params");
            }
            is_funccall=1;
            // cout<<"funcclass\n";
                $$->code=$2->code;
                // symbol_table_func funcst;
                // for(auto it:cls->member_funcs){

                // }
                
                string op = "push_param";
                quad* q5 = new quad("", $1->sym->lexeme, op, "");
                q5->make_code_push_param();
                $$->code.push_back(q5);
                
                string ag1='+'+to_string(8*(fun->params.size()-1));
                quad* q1 = new quad("", ag1, "", "");
                // q1->make_code_stack_pointer();
                // cout<<q1->code<<"\n";
                // $$->code.push_back(q1);

                // string arg1 = cls2->name+'.'+$2->sym->lexeme;
                string arg1 = cls2->name+'.'+$2->sym->lexeme;
                op="call_func";
                quad* q = new quad("", arg1, op, "");
                q->make_code_from_func_call();
                // cout<<q->code<<"\n";
                $$->code.push_back(q);

                ag1='-'+to_string(8*(fun->params.size()-1));
                quad* q2 = new quad("", ag1, "", "");
                // q2->make_code_stack_pointer();
                // cout<<q2->code<<"\n";
                // $$->code.push_back(q2);
            }
            
        }
        else if($2->label=="attribute"){
            // cout<<$1->type<<" taraa\n";
            string class_name=$1->type.substr(6,$1->type.size()-1);
            
            if(ogroot->look_up_class(class_name)==NULL){
                yyerror("class not declared");
            }
            symbol_table_class * cls=ogroot->look_up_class(class_name);
            bool found=false;
            int offset=0;
            for(auto it:cls->attrs){
                if(it->lexeme==$2->sym->lexeme){
                    found=true;
                    break;
                }
                offset++;
            }
            if(!found) yyerror("Attribute not defined");
            else{
                string tar=string("_t")+to_string(temp_cnt);
                string arg1 = $1->sym->lexeme;
                string arg2 = "";
                if(offset) arg2 = to_string(8*offset);
                temp_cnt++;
                // cout<<"argpr"<<arg2<<offset<<endl;
                quad* q1 = new quad(tar, arg1, "", arg2);
                q1->make_code_from_load();
                $$->code.push_back(q1);
                // $$->sym->lexeme = tar;
                trailer_attr=tar;
                // cout<<"atrr2 "<<trailer_attr<<endl;
            }
        }
        else if($2->label == "trailer_list"){
            $$->sym->is_attr = false;
            // cout<<"yay"<<endl;
            string arg1 = $1->sym->lexeme;
            string op = "+";
            string ind=$2->sym->lexeme;
            string arg2;
            if (ind[0]>='0' and ind[0]<='9')
            ind = to_string(stoi($2->sym->lexeme)*8);
            else {
                if (curr->look_up(ind)==NULL) yyerror("Index not found");
                else{
                    string tar=string("_t")+to_string(temp_cnt);
                    temp_cnt++;
                    // $$->listchk = "list_ind";
                    string op1="*";
                    arg2="8";
                    quad* q1 = new quad(tar, ind, op1, arg2);
                    q1->make_code_from_binary();
                    $$->code.push_back(q1);
                    ind=tar;
                }
             }
            string tar=string("_t")+to_string(temp_cnt);
            // temp_cnt++;
            $$->listchk = "list_ind";
            quad* q = new quad(tar, arg1, op, ind);
            q->make_code_from_binary();
            // cout<<"lst"<<q->code<<endl;
            $$->code.push_back(q);
        }
    }
    
    }

// trailer_: trailer_ trailer {$$=$1;$$->children.push_back($2); $$->sym=$2->sym;$$->Sym_list.push_back($2->sym);}| {$$=createNode("trailer_", "", {});}
atom: LPAREN testlist_comp RPAREN {Node *n1=createNode("Delimiter","(",{});Node *n2=createNode("Delimiter",")",{});$$=createNode("atom","",{n1,$2,n2});}|
        LEN LPAREN testlist_comp RPAREN {Node *n3=createNode("KEYWORD","len",{});Node *n1=createNode("Delimiter","(",{});Node *n2=createNode("Delimiter",")",{});$$=createNode("atom","",{n3,n1,$3,n2});} |
        //IDENTIFIER LPAREN testlist_comp RPAREN |
       LLIST testlist_comp RLIST {Node *n1=createNode("Delimiter","[",{});Node *n2=createNode("Delimiter","]",{});$$=createNode("atom","",{n1,$2,n2});$$->Sym_list=$2->Sym_list;$$->type="list";}|
       IDENTIFIER {
            // cout<<"p"<<endl;
            $$=createNode("Identifier",*$1,{});
            if(curr->look_up(*$1)==NULL){
                // cout<<*$1<<"not found\n";
            Symbol * temp = new Symbol(*$1,"id",yylineno);
            if(*$1=="print") is_print_string=1;
            $$->sym=temp;
            $$->type="identifier";
            temp->token = "IDENTIFIER";
            }
            else {$$->sym=curr->look_up(*$1);$$->type=$$->sym->type;}
        } 
       | NUMBER {$$=createNode("int",*$1,{});
            Symbol * temp = new Symbol(*$1,"int",yylineno);
            $$->sym=temp;
            $$->type="int";
            temp->token = "INT";
           }
       | string_pl{$$=$1;}
       | FLOATING_POINT {$$=createNode("float",*$1,{});
            Symbol * temp = new Symbol(*$1,"float",yylineno);
            $$->sym=temp;
            $$->type="float";
            temp->token = "FLOAT";
            }
       //| '...' 
       | NONE {$$=createNode("KEYWORD","None",{});
            } 
       | TRUE {$$=createNode("KEYWORD","True",{});
            } 
       | FALSE {$$=createNode("KEYWORD","False",{});
            }


string_pl: string_pl STR_LIT {$$=$1;Node * n1= createNode("string",*$2,{});$$->children.push_back(n1);} 
| STR_LIT {$$= createNode("string",*$1,{});
    // cout<<*$1<<" wert"<<endl;
    Symbol * temp = new Symbol(*$1,"string",yylineno);
            $$->sym=temp;
            $$->type="str";
            temp->token = "STR";    
    }
testlist_comp: {$$=createNode("testlist_comp","",{});}
    |test  testlist_comp_a {
    $$=createNode("testlist_comp","",{$1,$2});
    $$->sym=$1->sym;
    $$->Sym_list=$1->Sym_list;
    // cout<<"don1\n";
    $$->Sym_list.insert($$->Sym_list.end(),$2->Sym_list.begin(),$2->Sym_list.end());
    // cout<<"don0\n";
    }| star_expr testlist_comp_a {$$=createNode("testlist_comp","",{$1,$2});}
testlist_comp_a: comp_for {$$=$1;}| comma_testorstar COMMA {Node *n1=createNode("Delimiter",",",{});$$=createNode("testlist_comp_a","",{$1,n1});} | comma_testorstar {$$=$1;}
comma_testorstar: comma_testorstar COMMA test_or_starexpr {
    // $$=$1;
    $$=createNode("comma_testorstar", "", {});
    $$->Sym_list=$1->Sym_list;
    $$->sym=$1->sym;
    $$->Sym_list.insert($$->Sym_list.end(),$3->Sym_list.begin(),$3->Sym_list.end());
    Node *n1=createNode("Delimiter",",",{});
    $$->children.push_back(n1); $$->children.push_back($3);
} | {$$=createNode("comma_testorstar", "", {});}
test_or_starexpr: test {$$=$1;}| star_expr{$$=$1;}
trailer: LPAREN arglist RPAREN { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                $$=createNode("trailer_arglist", "", {n1, $2, n2});
                                
                                $$->Sym_list=$2->Sym_list;
                                reverse($2->code.begin(), $2->code.end());
                                $$->code=$2->code;
                            }
                                | LPAREN RPAREN { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                $$=createNode("trailer_arglist", "", {n1, n2});}
                                | LLIST subscriptlist RLIST { Node *n1=createNode("Delimiter", "[", {}); 
                                Node *n2=createNode("Delimiter", "]", {});
                                $$=createNode("trailer_list", "", {n1, $2, n2});
                                $$->sym=$2->sym;
                                if($$->sym->type!="int") yyerror("List index can be int only");
                                // cout<<"list index\n";
                                }
                                | DOT IDENTIFIER { Node *n1=createNode("Delimiter", ".", {}); 
                                Node *n2=createNode("Identifier", *$2, {});
                                $$=createNode("attribute", "", {n1, n2});
                                Symbol * temp = new Symbol(*$2,"identifier",yylineno);
                                $$->sym = temp;
                                // cout<<"atrribute "<<*$2<<endl;
                                }
                                | DOT IDENTIFIER LPAREN arglist RPAREN{ Node *n1=createNode("Delimiter", ".", {}); 
                                Node *n2=createNode("Identifier", *$2, {});
                                Node *n3=createNode("Delimiter", "(", {}); 
                                Node *n4=createNode("Delimiter", ")", {});
                                $$=createNode("trailer_method", "", {n1, n2, n3, $4, n4});
                                Symbol * temp = new Symbol(*$2,"identifier",yylineno);
                                $$->sym = temp;
                                $$->Sym_list=$4->Sym_list;
                                $$->code=$4->code;
                                }
                                | DOT IDENTIFIER LPAREN RPAREN{ Node *n1=createNode("Delimiter", ".", {}); 
                                Node *n2=createNode("Identifier", *$2, {});
                                Node *n3=createNode("Delimiter", "(", {}); 
                                Node *n4=createNode("Delimiter", ")", {});
                                $$=createNode("trailer_method", "", {n1, n2, n3, n4});
                                Symbol * temp = new Symbol(*$2,"identifier",yylineno);
                                $$->sym = temp;
                                }
                                | {$$=createNode("Null","",{});}
subscriptlist: subscript comma_subscript COMMA { Node *n1=createNode("Delimiter", ",", {});
                                $$=createNode("subscriptlist", "", {$1, $2, n1}); $$->code = $1->code;}
                                | subscript comma_subscript { $$=createNode("subscriptlist", "", {$1, $2});$$->sym=$1->sym;$$->Sym_list=$1->Sym_list; $$->code = $1->code;}
comma_subscript: comma_subscript COMMA subscript { $$=$1; Node *n1=createNode("Delimiter", ",", {});
                                $$->children.push_back(n1); $$->children.push_back($3);}
                                | {$$=createNode("comma_subscript", "", {});}
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
exprlist: expr_str comm_exstr COMMA { 
                                    Node *n1=createNode("Delimiter", ",", {});
                                    $$=createNode("exprlist", "", {$1, $2, n1});
                                    $$->code = $1->code;
                                    $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                    $$->resset.push_back($1->res);
                                    $$->resset.insert($$->resset.end(), $2->resset.begin(), $2->resset.end());
                                    }
            | expr_str comm_exstr {
                                    $$=createNode("exprlist", "", {$1, $2});
                                    $$->resset.push_back($1->res);
                                    $$->resset.insert($$->resset.end(), $2->resset.begin(), $2->resset.end());
                                    }
expr_str: expr{$$=$1;}|star_expr{$$=$1;}
comm_exstr: comm_exstr COMMA expr_str {
                                        $$=$1;
                                        Node *n1=createNode("Delimiter", ",", {});
                                        $$->children.push_back(n1); $$->children.push_back($3);
                                        $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                        $$->resset.push_back($3->res);
                                        }
            | {$$=createNode("comm_exstr", "", {});}
testlist: test comm_test COMMA { 
                                Node *n1=createNode("Delimiter", ",", {});
                                $$=createNode("testlist", "", {$1, $2, n1});
                                $$->code=$1->code;
                                $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                if($1->res != "") $$->resset.push_back($1->res);
                                if(!$2->resset.empty()) $$->resset.insert($$->resset.end(), $2->resset.begin(), $2->resset.end());
                                }
        | test comm_test {$$=createNode("testlist", "", {$1, $2}); $$->code=$1->code; $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end()); if($1->res != "") $$->resset.push_back($1->res); if(!$2->resset.empty()) $$->resset.insert($$->resset.end(), $2->resset.begin(), $2->resset.end()); $$->is_attr = $1->sym->is_attr;}
comm_test: comm_test COMMA test {$$=$1; Node *n1=createNode("Delimiter", ",", {}); 
                        $$->children.push_back(n1); 
                        $$->children.push_back($3); $$->code.insert($$->code.end(),  $3->code.begin(), $3->code.end());
                        if(!$1->resset.empty()) $$->resset.insert($$->resset.end(), $1->resset.begin(), $1->resset.end());
                        if($3->res != "") $$->resset.push_back($3->res);} 
                        | {$$=createNode("comm_test", "", {});}

dictorsetmaker: testcoltest_powexpr compfor_comtestpowcom {$$=createNode("dictorsetmaker", "", {$1, $2});}|  test_or_starexpr compfor_comteststarcom {$$=createNode("dictorsetmaker", "", {$1, $2});}

compfor_comtestpowcom: comp_for {$$=$1;}| comma_testpow COMMA { Node *n1=createNode("Delimiter", ",", {}); $$=createNode("compfor_comtestpowcom", "", {$1, n1});}| comma_testpow {$$=$1;}
compfor_comteststarcom: comp_for {$$=$1;}| comma_testorstar COMMA { Node *n1=createNode("Delimiter", ",", {}); $$=createNode("compfor_comteststarcom", "", {$1, n1});} | comma_testorstar {$$=$1;}
testcoltest_powexpr: test COLON test { Node *n1=createNode("Delimiter", ":", {}); $$=createNode("testcoltest_powexpr", "", {$1, n1, $3});} | POW expr { Node *n1=createNode("Operator", "**", {}); $$=createNode("testcoltest_powexpr", "", {n1, $2});}
comma_testpow: comma_testpow COMMA testcoltest_powexpr { $$=$1;Node *n1=createNode("Delimiter", ",", {}); $$->children.push_back(n1);$$->children.push_back($3);} | {$$ = createNode("comma_testpow","",{});} 
classdef: CLASS IDENTIFIER {symbol_table_class * stclass = new symbol_table_class(*$2);
                            ogroot->add_entry(stclass);curr->add_scope(stclass);
                            Symbol * temp = new Symbol(*$2, "class_"+*$2, yylineno);
                            temp->is_class=true;curr->add_entry(temp);
                            curr=stclass;
                            } l_arglist_r_maybe {
                                    vector<symbol_table_func *> member_funcs_new;
                                symbol_table_class *cls=(symbol_table_class *)curr;
                                symbol_table_class *bs;
                                for(auto base:$4->Sym_list){
                                    if(ogroot->look_up_class(base->lexeme)==NULL) yyerror("Undeclared class used as base");
                                    else{
                                        bs=ogroot->look_up_class(base->lexeme);
                                        cls->parent_name = bs->name;
                                        // cout<<"parent "<<bs->name<<endl;
                                        // for(auto at:cls->attrs){
                                        //     cout<<"1 "<<at->lexeme<<endl;
                                        // }
                                        for(auto it:bs->attrs){
                                            cls->attrs.push_back(it);
                                            // cout<<it->lexeme<<endl;
                                        }
                                        // for(auto at:cls->attrs){
                                        //     cout<<at->lexeme<<endl;
                                        // }
                                        for(auto f:bs->member_funcs){
                                            if(f->name!="__init__"){
                                                cls->member_funcs.push_back(f);
                                                member_funcs_new.push_back(f);
                                            }
                                        }

                                        // for(auto it:cls->attrs) cout<<"atrrib base"<<it->lexeme<<endl;
                                        // for(auto it:cls->member_funcs) cout<<"memberfunc base"<<it->name<<endl;
                                    }
                                }
                                }
                                COLON suite { 
                                
                                Node *n1=createNode("KEYWORD", "CLASS", {}); 
                                Node *n2=createNode("Identifier", *$2, {});
                                Node *n3=createNode("Delimiter", ":", {});
                                $$=createNode("classdef", "", {n1, n2, $4, n3, $7});
                                // for(auto base:$4->Sym_list){
                                //     if(ogroot->look_up_class(base->lexeme)==NULL) yyerror("Undeclared class used as base");
                                //     else{
                                //         symbol_table_class *bs=ogroot->look_up_class(base->lexeme);
                                //         for(auto it:bs->attrs) cls->attrs.push_back(it);
                                //         for(auto f:bs->member_funcs){
                                //             if(f->name!="__init__"){
                                //                 cls->member_funcs.push_back(f);
                                //             }
                                //         }

                                //         for(auto it:cls->attrs) cout<<"atrrib base"<<it->lexeme<<endl;
                                        
                                //     }
                                // }

                                symbol_table_func* init=curr->look_upfunc("__init__");
                                // cout<<"looks\n";
                                if(init==NULL) yyerror("init func not defined");
                                else{
                                    symbol_table_class *cls=(symbol_table_class *)curr;
                                    for(auto pr:init->params){
                                        if(pr->lexeme!="self") cls->params.push_back(pr);
                                    }
                                    // for(auto it:init->entries){
                                    //     cls->attrs.push_back(it);
                                    // }
                                    // for(auto it:cls->attrs) cout<<"atrrib "<<it->lexeme<<endl;
                                }
                                symbol_table_class* cls = (symbol_table_class*)curr;
                                curr=curr->parent;
                                $$->code.insert($$->code.end(), $4->code.begin(), $4->code.end());
                                string arg1=*$2;
                                quad* q = new quad("", arg1, "", "");
                                q->make_code_begin_class();
                                // $$->code.push_back(q);
                                ircode.push_back(q);
                                $$->code.insert($$->code.end(), $7->code.begin(), $7->code.end());
                                // for(auto it:cls->attrs){
                                //     cout<<cls->name<<" "<<it->lexeme<<endl;
                                // }
                                // vector<quad*> funcs_code;
                                // for(auto fnc:member_funcs_new){
                                //     string argfun = curr2->name + '.' + fnc->name;
                                //     quad* qb = new quad("", argfun, "", "");
                                //     qb->make_code_begin_func();
                                //     funcs_code.push_back(qb);
                                //     for(auto cd:fnc->codes){
                                //         string str1 = "*(";
                                //         // size_t found = str.find(str1);
                                //         // if (found != string::npos){
                                            
                                //         // }
                                //     }
                                // }
                                // $$->code.insert($$->code.end(), funcs_code.begin(), funcs_code.end());
                                quad* q1 = new quad("", "", "", "");
                                q1->make_code_end_class(); 
                                // $$->code.push_back(q1);
                                ircode.push_back(q1);
                                // for(auto cd:$$->code) cout<<"class "<<cd->code<<endl;
                                }
l_arglist_r_maybe: LPAREN arglist RPAREN { Node *n1=createNode("Delimiter", "(", {}); 
                                Node *n2=createNode("Delimiter", ")", {});
                                $$=createNode("l_arglist_r_maybe", "", {n1, $2, n2});
                                $$->Sym_list=$2->Sym_list;
                                $$->code=$2->code;
                                
                                } | {$$=createNode("l_arglist_r_maybe", "", {});}

arglist: argument comm_arg COMMA {
                                    Node *n1=createNode("Delimiter", ",", {});
                                    $$=createNode("arglist", "", {$1, $2, n1}); 
                                    $$->Sym_list.push_back($1->sym);
                                    // $$->Sym_list=$2->Sym_list; 
                                    for(auto &it:$2->Sym_list) $$->Sym_list.push_back(it);
                                    $$->code=$1->code;
                                    $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                                    } 
        | argument comm_arg {$$=createNode("arglist", "", {$1, $2});
                            $$->Sym_list.push_back($1->sym);
                                    // $$->Sym_list=$2->Sym_list; 
                                    for(auto &it:$2->Sym_list) $$->Sym_list.push_back(it);
                            $$->code=$1->code;
                            $$->code.insert($$->code.end(), $2->code.begin(), $2->code.end());
                            }
comm_arg: comm_arg COMMA argument {
                                    $$=createNode("comm_arg", "", {});
                                    $$->Sym_list.insert($$->Sym_list.end(),$1->Sym_list.begin(),$1->Sym_list.end());
                                    Node *n1=createNode("Delimiter", ",", {});
                                    $$->code=$1->code;
                                    $$->children.push_back(n1);
                                    $$->children.push_back($3);
                                    $$->Sym_list.push_back($3->sym);
                                    $$->code.insert($$->code.end(), $3->code.begin(), $3->code.end());
                                    }
        | {$$=createNode("comm_arg", "", {});}
argument:  test comp_for {$$=createNode("argument", "", {$1, $2});}|
            test {$$=$1; 
            // cout<<"argument\n";
                int flag=0; 
                string type; 
                for(auto &i:$1->Sym_list){
                    if (i==NULL) continue;
                    if(flag==0){
                        type = i->type;
                        flag=1;
                    }
                    if(i->type != type) yyerror("Type mismatch");
                    if (i->type=="id" && curr->look_up(i->lexeme)==NULL){
                        yyerror("Not declared");
                    }
                }

                string op="push_param";
                quad* q = new quad("", $1->res, op, ""); 
                q->make_code_push_param();
                // cout<<"is_print_string"<<is_print_string<<" "<<type<<endl;
                if(is_print_string && type!="string"){
                $$->code.push_back(q); reverse($$->code.begin(),$$->code.end());}
                else if(!is_print_string){
                    $$->code.push_back(q);
                    reverse($$->code.begin(),$$->code.end());
                     
                }
                ircode.push_back(q);
                // cout<<"arg done\n"<<q->code<<endl;
                }
        | test EQUALS test { Node *n1=createNode("Equals", "=", {}); $$=createNode("argument", "", {$1, n1, $3});}
        | POW test { Node *n1=createNode("Operator", "**", {}); $$=createNode("argument", "", {n1, $2});}
        | TIMES test { Node *n1=createNode("Operator", "*", {}); $$=createNode("argument", "", {n1, $2});}

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
    // cout<<"abort-1\n";
    Node * n1=createNode("Newline","nl",{});Node * n2=createNode("Indent","Indent",{});Node * n3=createNode("Dedent","Dedent",{});
    $$=createNode("func_body_suite","",{n1,n2,$3,n3}); $$->code=$3->code;
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
    cout << "-o, --output <output_file_name>\t\t\t Redirect x86 file to output file\n";
    cout << "-v, --verbose \t\t\t\t\t Outputs the entire derivation in command line\n";
    return;
}


int main (int argc, char *argv[]) {
    bool verbose=false;
    if(argc==1){
        cout<<"Incorrect no of arguments"<<endl;
        return -1;
    }
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
    // generateDotFile(output_file);
    
    fclose(program);
    return 1;
}