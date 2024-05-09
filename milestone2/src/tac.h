#include <bits/stdc++.h>
using namespace std;

class quad{
    public:
        string op;
        string result;
        string arg1;
        string arg2;
        string code="";
        int rel_jump = 0, abs_jump = 0, ins_line = 0;
        int made_from = 0;
        bool is_target = false;

        enum code_code {
        BINARY,
        UNARY,
        ASSIGNMENT,
        CONDITIONAL,
        CAST,
        STORE,
        LOAD,
        FUNC_CALL,
        CTOR_CALL,
        GOTO,
        BEGIN_FUNC,
        END_FUNC,
        BEGIN_CLASS,
        END_CLASS,
        MEMALLOC,
        RETURN,
        STACK_POINTER,
        PUSH_PARAM,
        POP_PARAM,
        RETURN_VAL
    };
        quad();
        quad(string r, string a1, string o, string a2);     // res = arg1 op arg2
        void make_code();                                   // Recreate code
        void make_code_from_binary();                       // r = a1 op a2;
        void make_code_from_unary();                        // r = op a1;
        void make_code_from_assignment();                   // r = a1;
        void make_code_from_conditional();                  // IFTRUE/FALSE a1 GOTO [filled later using check_jump()];
        void make_code_from_cast();                         // r = (a2) a1;
        void make_code_from_store();                        // *(r) = a1;
        void make_code_from_load();                         // r = *(a1);
        void make_code_from_func_call();                    // callfunc a1;
        void make_code_from_ctor_call();                    // callctor a1;
        void make_code_from_goto();                         // GOTO a1;
        void make_code_begin_func();                        // begin_func x;
        void make_code_from_memalloc();
        void make_code_end_func();                          // end_func;
        void make_code_begin_class();                        // begin_class x;
        void make_code_end_class();                          // end_class;
        void make_code_from_return();                       // return a1;
        void make_code_stack_pointer();                     // shift stack pointer
        void make_code_push_param();                        // pushparam a1;
        void make_code_pop_param();                         // r = popparam;
        void make_code_from_return_val();                   // r = return_value;
        void check_jump(const int); 
};