#include<bits/stdc++.h>
#include "symbol.h"

using namespace std;
int num_scopes=0;
symbol_table_global *main_st = new symbol_table_global();

Symbol::Symbol(){;}
Symbol::Symbol(string lexeme,int type,int line_no,int size){
    this->lexeme=lexeme;
    this->type=type;
    this->line_no=line_no;
    this->size=size;
    this->access_type=PUBLIC_ACCESS;
    this->is_decl=true;
}
Symbol::Symbol(string lexeme,int type,int line_no){
    this->lexeme=lexeme;
    this->type=type;
    this->line_no=line_no;
    // this->size=size;
    this->access_type=PUBLIC_ACCESS;
    this->is_decl=true;
}
Symbol::Symbol(string lexeme,int type,int line_no,int size,int access_type){
    this->lexeme=lexeme;
    this->type=type;
    this->line_no=line_no;
    this->size=size;
    this->access_type=access_type;
    this->is_decl=true;
}

void Symbol::printSym()
{
    cout << this->lexeme << " " << this->type << " " << this->line_no << endl;
    // if (this->isArray)
    // {
    //     cout << this->width1 << " " << this->width2 << " " << this->width3 << "\n";
    // }
}

symbol_table::symbol_table(){
    this -> scope = "";
    this -> name = "";
    this -> symbol_table_category = 'B';
}

symbol_table::symbol_table(string name) {
    this -> scope = "";
    this -> name = name;
    this -> symbol_table_category = 'B';
}

void symbol_table::add_scope(symbol_table* st){
    this->sub_scopes++;
    st->scope = scope + "." + to_string(this->sub_scopes);
    st->parent_st = this;    // st is the child symbol table, this pointer gives the parent symbol table
}

void symbol_table::add_entry(Symbol* new_entry){
    for(int i = 0; i < new_entry -> dimensions; i++) {
        new_entry -> type += "[]";
    }
    new_entry -> update_type(new_entry -> type);

    for(auto (&entry) : entries){
        if(new_entry->name == entry->name){
            cout << "ERROR: Variable " << new_entry->name << " is already declared at line number " << entry->line_no << " in the same scope.\n";
            exit(1);
        }
    }
    entries.push_back(new_entry);
    new_entry -> table = this;
}

void symbol_table::delete_entry(string name){
    for(auto ite = entries.begin(); ite != entries.end(); ite++){
        if((*ite) -> name == name){
            entries.erase(ite);
            return;
        }
    }

    cout<<"There is no entry with variable name " << name << " in scope " << scope << ".\n";
    cout<<"Returning without deleting...\n";
}

int symbol_table::get_localspace_size() {
    int space = 0;

    for(auto &entry : this -> entries) {
        space += entry -> size;
    }

    return space;
}

Symbol* symbol_table::look_up(string name){
    //! populate the global symbol table entry list with class names so that lookup here is possible !//
    if(this -> symbol_table_category == 'G') {
        return NULL;  // use main_table -> look_up_class() for these   
    }

    if(this -> symbol_table_category == 'M') {
        symbol_table_func* tmp = (symbol_table_func *) this;
        for(ull idx = 0; idx < tmp -> params.size(); idx++) {
            if(tmp -> params[idx]-> name == name) {
                return tmp -> params[idx];
            }
        } 
    }
    for(ull idx = 0; idx < entries.size(); idx++){
        if(entries[idx]->name == name){
            return entries[idx];
        }
    }
    
    if(this->parent_st){
        return this->parent_st->look_up(name);
    }

    return NULL;
}

