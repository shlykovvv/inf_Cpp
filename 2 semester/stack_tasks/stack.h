#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H
#define MAX 100

struct stack {
    char elem[MAX];
    int top;
};

void init(stack *stk);

void push(stack *stk, char f);

char pop(stack *stk);

char stkTop(stack *stk);

int getcount(stack *stk);

int isempty(stack *stk);

void stkPrint(stack *stk);

#endif //UNTITLED_STACK_H
