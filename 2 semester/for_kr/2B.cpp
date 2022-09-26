#include <iostream>
#include "list.h"

int getCycle(Node** head)
{
    auto slow = (*head)->next;
    auto fast = (*head)->next->next;
    while (slow != nullptr & fast != nullptr) {
        if (slow == fast) {
            slow = *head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow->value;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return -1;
}

int main() {
    List l;
    l.size = 0;
    push_back(&l, 1);
    push_back(&l, 2);
    push_back(&l, 3);
    Node *temp = l.tail;
    push_back(&l, 4);
    push_back(&l, 5);
    push_back(&l, 6);
    l.tail->next = temp;
    std::cout << getCycle(&l.head);
}
