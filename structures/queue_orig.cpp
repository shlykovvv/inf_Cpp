#include <iostream>
#define MAX 100

struct queue {
    int qu[MAX];
    int rear, frnt;
};

void init(queue *q) {
    q->frnt = 1;
    q->rear = 0;
    return;
}

void insert(queue *q, int x) {
    if(q->rear < MAX-1) {
        q->rear++;
        q->qu[q->rear]=x;
    }
    else
        std::cout << "queue is full";
    return;
}

int isempty(struct queue *q) {
    if(q->rear < q->frnt)    return 1;
    else  return 0;
}

void print(struct queue *q) {
    int h;
    if(isempty(q)==1) {
        std::cout << "queue is empty" << std::endl;
        return;
    }
    for(h = q->frnt; h<= q->rear; h++)
        std::cout << q->qu[h] << ' ';
    std::cout << '\n';
    return;
}

int remove(struct queue *q) {
    int x, h;
    if(isempty(q)==1) {
        std::cout << "queue is empty";
        return 0;
    }
    x = q->qu[q->frnt];
    for(h = q->frnt; h < q->rear; h++) {
        q->qu[h] = q->qu[h+1];
    }
    q->rear--;
    return x;
}

int main() {
    queue q{};
    init(&q);
    insert(&q, 1);
    insert(&q, 2);
    insert(&q, 3);
    print(&q);
    remove(&q);
    print(&q);
    remove(&q);
    remove(&q);
    remove(&q);
    return 0;
}