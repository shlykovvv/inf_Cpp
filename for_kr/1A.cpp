#include <iostream>
#include "list.h"

void reverse(Node ** head)
{
    if (*head == nullptr) return;
    struct Node *curr, *next, *prev = nullptr;
    curr = *head;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    List l{};
    push_back(&l, 10);
    push_back(&l, 20);
    push_back(&l, 30);
    push_back(&l, 40);
    reverse(&l.head);
    printlist(&l);
}
