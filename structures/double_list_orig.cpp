#include <iostream>

struct Node
{
    int value;
    Node* next;
    Node* prev;
};

struct List {
    int size;
    Node* head;
    Node* tail;
};

void push_back(List* list, int new_val)
{
    Node* node = new Node;
    node->value = new_val;
    node->prev = list->tail;
    if (list->size == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else {
        list->tail->next = node;
        list->tail = node;


    }
    list->size += 1;
}

void push_front(List* list, int new_val)
{
    Node* node = new Node;
    node->value = new_val;
    node->next = list->head;
    if (list->size == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->head->prev = node;
        list->head = node;
    }
    list->size += 1;
}

void insert(List* list, int new_val, int n)
{
    Node* node = new Node;
    node->value = new_val;
    if (list->size == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        Node* node_prev = list->head;
        Node* node_next = list->head;
        for (int i = 0; i < n; i++)
        {
            node_prev = node_next;
            node_next = node_next->next;
            if (node_prev == list->tail)
            {
                break;
            }
        }
        if (n != 0)
        {
            node_prev->next = node;
            node->prev = node_prev;
            node->next = node_next;
            if (node_next != nullptr) {
                node_next->prev = node;
            }
        }
        if (n == 0)
        {
            list->head = node;
            node->next = node_next;
            node_next->prev = node;
        }
    }
    list->size = list->size + 1;
}

int pop_back(List* list)
{
    int a;
    if (list->size > 1)
    {
        a = list->tail->value;
        list->tail = list->tail->prev;
        list->tail->next = nullptr;
        list->size = list->size - 1;
    }
    else
    {
        a = 0;
        list->head = nullptr;
        list->tail = nullptr;
        list->size = list->size - 1;
    }
    return a;
}

int pop_front(List* list)
{
    int a;
    if ( list->size > 1)
    {
        a = list->head->value;
        list->head = list->head->next;
        list->head->prev = nullptr;
        list->size = list->size - 1;
    }
    else
    {
        a = 0;
        list->head = nullptr;
        list->tail = nullptr;
        list->size = list->size - 1;
    }
    return a;
}

void remove(List* list, int i)
{
    if ((i != list->size - 1) && (i != 0))
    {
        Node* node_prev = list->head;
        for (int j = 0; j < i - 1; j++)
        {
            node_prev = node_prev->next;
        }
        node_prev->next = node_prev->next->next;
        node_prev->next->prev = node_prev;
        list->size -= 1;
    }
    else if (i == 0)
    {
        list->head = list->head->next;
        list->head->prev = nullptr;
        list->size -= 1;
    }
    else if (i == list->size - 1)
    {
        pop_back(list);
    }
}

int get(List* list, int i)
{
    Node* node = list->head;
    for (int k = 0; k < i; k++)
    {
        node = node->next;
    }
    return node->value;
}

void clear(List* list)
{
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
}

void printlist(List* list)
{
    int n = list->size;
    if (n == 0) {
        std::cout << "list is empty" << std::endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << get(list, i) << ", ";
    }
    std::cout << get(list, n - 1) << std::endl;
}

int main() {
    List l;
    l.size = 0;
    push_back(&l, 10);
    push_back(&l, 20);
    push_back(&l, 30);
    printlist(&l);
    insert(&l, 25, 2);
    insert(&l, 5, 0);
    printlist(&l);
    remove(&l, 3);
    remove(&l, 3);
    remove(&l, 0);
    printlist(&l);
    clear(&l);
    printlist(&l);
}