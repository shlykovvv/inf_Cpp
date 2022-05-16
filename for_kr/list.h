#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

struct Node
{
    int value;
    Node* next;
};

struct List {
    int size;
    Node* head;
    Node* tail;
};

void push_back(List* list, int new_val);

void push_front(List* list, int new_val);

void insert(List* list, int new_val, int n);

int pop_back(List* list);

int pop_front(List* list);

void remove(List* list, int i);

int get(List* list, int i);

void clear(List* list);

void printlist(List* list);

#endif //UNTITLED_LIST_H
