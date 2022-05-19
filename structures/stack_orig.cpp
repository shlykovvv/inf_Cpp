#include <iostream>
#define MAX 100

struct stack {
    float elem[MAX];
    int top;
};

void init(stack *stk) {
    stk->top = 0;
}

void push(stack *stk, float f) {
    if(stk->top < MAX) {
        stk->elem[stk->top] = f;
        stk->top++;
    } else
        std::cout << "stack is full" << std::endl;
}

float pop(stack *stk) {
    float elem;
    if((stk->top) > 0)
    {
        stk->top--;
        elem = stk->elem[stk->top];
        return elem;
    }
    else
    {
        std::cout << "stack is empty" << std::endl;
        return 0;
    }
}

float stkTop(stack *stk) {
    if((stk->top) > 0) {
        return stk->elem[stk->top-1];
    } else {
        std::cout << "stack is empty" << std::endl;
        return 0;
    }
}

int getcount(stack *stk) {
    return stk->top;
}

int isempty(stack *stk) {
    if(stk->top == 0)    return 1;
    else return 0;
}

void stkPrint(stack *stk) {
    int i;
    i=stk->top;
    if(isempty(stk) == 1) return;
    do {
        i--;
        std::cout << stk->elem[i] << ' ';
    }while(i>0);
    std::cout << std::endl;
}

int main() {
    stack stk{};
    init(&stk);
    push(&stk, 1);
    push(&stk, 2);
    push(&stk, 3);
    stkPrint(&stk);
    pop(&stk);
    stkPrint(&stk);
    pop(&stk);
    pop(&stk);
    pop(&stk);
    return 0;
}