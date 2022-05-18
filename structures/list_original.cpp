#include <iostream>

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

void push_back(List* list, int new_val)
{
    Node* node = new Node;
    node->value = new_val;
    node->next = nullptr;
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
                list->tail->next = node;
                list->tail = node;
            }
        }
        if (n != 0)
        {
            node_prev->next = node;
            node->next = node_next;
        }
        if (n == 0)
        {
            list->head = node;
            node->next = node_next;
        }

    }
    list->size = list->size + 1;
}

int pop_back(List* list)
{
    int a = list->tail->value;
    Node* element = list->head;
    if ( list->size > 1)
    {
        for (int i = 0; i < list->size - 2; i++)
        {
            element = element->next;
        }
        element->next = nullptr;
        list->tail = element;
        list->size = list->size - 1;
    }
    else
    {
        list->head = nullptr;
        list->tail = nullptr;
        list->size = list->size - 1;
    }
    return a;
}

int pop_front(List* list)
{
    int a = list->head->value;
    Node* element = list->head;
    if (list->size > 1)
    {
        for (int i = 0; i < list->size - 2; i++)
        {
            element = element->next;
        }
        list->tail = element;
        list->size = list->size - 1;
    }
    else
    {
        list->head = nullptr;
        list->tail = nullptr;
        list->size = 0;
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
        list->size -= 1;
    }
    else if (i == 0)
    {
        list->head = list->head->next;
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

int main()
{
    List l{};
    push_back(&l, 10);
    push_back(&l, 20);
    push_back(&l, 30);
    printlist(&l);
    insert(&l, 25, 2);
    insert(&l, 5, 0);
    printlist(&l);
    remove(&l, 3);
    remove(&l, 3);
    printlist(&l);
    clear(&l);
    printlist(&l);
}