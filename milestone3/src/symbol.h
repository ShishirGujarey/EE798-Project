#include <bits/stdc++.h>
using namespace std;

#define PUBLIC_ACCESS 0
#define PRIVATE_ACCESS 1
#define PROTECTED_ACCESS 2
#include "tac.h"

// extern Node* root;
class symbol_table;
class symbol_table_func;
class Symbol
{
public:
    string lexeme;
    string type;
    string token;
    int line_no;
    int size;
    int offset;
    int dimensions;
    bool is_decl = false;
    int access_type = PUBLIC_ACCESS;
    bool is_class = false;
    bool is_func = false;
    bool is_attr=false;
    bool modifier_bv[10] = {0};
    symbol_table *table;
    Symbol();
    Symbol(string lexeme, string type, int line_no, int size);
    Symbol(string lexeme, string type, int line_no);
    Symbol(string lexeme, string type, int line_no, int size, int access_type);
    void update_type(string type);
    void printSym();
};

class symbol_table
{
    public:
    vector<Symbol *> entries;
    string scope, name;

    symbol_table *parent = NULL;
    vector<symbol_table *> children_st;
    char st_category = 'O'; // GLOBAL: G || CLASS: C || METHOD : M || BLOCK : B || OTHER : O
    int sub_scopes = 0;
    int scope_start_line_no = 0;
    symbol_table();
    symbol_table(string name);

    void add_scope(symbol_table *st);

    void add_entry(Symbol *entry);
    void delete_entry(string name);

    
    symbol_table_func* look_upfunc(string name);
    Symbol *look_up(string name);
    void make_csv(string filename = "symbol_table.csv");
    void make_csv_wrapper(string filename="symtab.csv");
    int get_localspace_size();
};

class symbol_table_func : public symbol_table
{
    public:
    vector<Symbol *> params;
    string return_type;
    bool modifier_bv[10] = {0};
    vector<quad *> codes;
    
    symbol_table_func(string func_name, vector<Symbol *>(&params), string return_type);

    void add_entry(Symbol *new_entry);

    void update_modifiers(vector<Symbol *> modifiers);

    int get_localspace_size();

    bool operator==(const symbol_table_func &other);

    void make_csv(string filename);
};

class symbol_table_class : public symbol_table
{
    public:
    // Stores member variables and a list of Function-Symbol tables for member functions
    vector<symbol_table_func *> member_funcs;
    vector<Symbol *> params;
    vector<Symbol*> attrs;
    string parent_name = "global";
    int object_size = 0;
    bool modifier_bv[10] = {0};
    bool needs_constructor = false;

    symbol_table_class(string class_name);
    void add_init_params(vector<Symbol*> params);
    void add_func(symbol_table_func *func);
    symbol_table_func *look_up_function(string &name, vector<string> &params);

    void update_modifiers(vector<Symbol *> modifiers);

    void make_csv(string filename);
};

class symbol_table_global : public symbol_table
{
    public:
    // Stores classes
    vector<Symbol *> entries;
    vector<symbol_table_class *> classes;
    vector<symbol_table_func *> funcs;
    // vector<symbol_table *> sym_tabs;
    symbol_table_global();
    void add_entry(symbol_table_class *new_cls);
    void add_entry(symbol_table_func *new_func);
    // void add_entry(symbol_table *new_st);
    void add_entry(Symbol *entry);
    symbol_table_func *look_up_func(string cls_name);
    symbol_table_class *look_up_class(string cls_name);

    void make_csv(string filename= "symbol_table.csv");
    void add_SysOutPln();
};