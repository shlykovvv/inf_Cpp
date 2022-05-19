#include <iostream>
#include <string>
#include "stack.h"

int delete_touching(stack &st, stack &st2){
    int size = st.top;
    while (st.top > 0){
        if (stkTop(&st) == '('){
            if (stkTop(&st2) == '('){
                pop(&st2);
            }else{
                push(&st2, ')');
            }
        }
        if (stkTop(&st) == ')'){
            push(&st2, '(');
        }

        if (stkTop(&st) == '{'){
            if (stkTop(&st2) == '{'){
                pop(&st2);
            }else{
                push(&st2, '}');
            }
        }
        if (stkTop(&st) == '}'){
            push(&st2, '{');
        }

        if (stkTop(&st) == '['){
            if (stkTop(&st2) == '['){
                pop(&st2);
            }else{
                push(&st2, ']');
            }
        }
        if (stkTop(&st) == ']'){
            push(&st2, '[');
        }
        pop(&st);
    }
    if (st2.top == 0){
        return 0;
    }
    if (st2.top == size){
        return -1;
    }
    delete_touching(st2, st);
}

int main()
{
    std::string s;
    std::cin >> s;
    stack st{};
    init(&st);
    for (int i = 0; i < s.length(); i++){
        push(&st, s[i]);
    }

    int res = -1;
    stack st2{};
    init(&st2);
    if (st.top % 2 == 0){
        res = delete_touching(st, st2);
    }
    std::cout << res;
    return 0;
}