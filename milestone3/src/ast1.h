#ifndef CP_H
#define CP_H
#include<bits/stdc++.h>
#include "symbol.h"
// #include "tac.h"
using namespace std;


// vector<quad*> ircode;
class Node
{

public:
  string label;
  string value;
  // string e_label;
  vector<Node *> children;
  string type="";
  Node* parent=NULL;
  int line_no;
  int last=-1;
  vector<int> truelist,falselist,nextlist;
  symbol_table * sym_tab;
  Symbol * sym=NULL;
  vector<Symbol*> Sym_list;
  vector<quad*> code;
  vector<string> resset;
  string res="";
  string listchk="";
  string op="";
  bool is_empty=false;
  bool is_attr=false;
};
// extern Node * root;
#endif