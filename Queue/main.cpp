//queue implmentation
//linked list + queue


#include <iostream>
using namespace std;

typedef struct link
{
    int element;
    link *next;
}Link;

Link createLink(int newElement, Link newNext) {
    Link* n = (Link*) malloc(sizeof(Link));
    n->element = newElement;
    n->next = newNext;
    return n;
}

Link createEmptyLink(Link newNext) {
    Link* n = (Link*) malloc(sizeof(Link));
    n->next = newNext;
    return n;
}

typedef struct list
{
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
}List;

List *createList() {
    List l = (List) malloc(sizeof(List));
    l->curr = l->tail = l->head = createEmptyLink(NULL);
    l->cnt = 0;
    return l;
}

// void insert(List* l, int it) {
//     l->curr->next = createLink(it, l->curr->next);
//     if (l->tail == l->curr)
//     {
//         l->tail = l->curr->next;
//     }
//     l->cnt++;

// }

void moveToStart(List* l) {
    l->curr = l->head;
}

void next(List* l) {
    l->curr = l->curr->next;
}

void prev(List* l) {
    if (l->curr == l->head)
    {
        return;
    }
    Link* temp = l->head;
    while (temp->next != l->curr)
    {
        temp = temp->next;
    }
    l->curr = temp;

}

// int remove(List *l) {
//     if (l->curr->next == NUUL)
//     {
//         return NULL;
//     }
//     int it = l->curr->next->element;
//     if (l->tail = l->curr->next)
//     {
//         l->tail = l->curr;
//     }
//     l->curr->next = l->curr->next->next;
//     l->cnt--;
//     return it;
// }

// void clear(Queue q);
// void enqueue(Queue q, E it);
// E dequeue(Queue q);
// E frontValue(Queue q);
// int length(Queue q);

typedef struct queue
{
    Link *front;
    Link* rear;
    int size;
}Queue;

Queue *createQueue() {
    Queue q = (Queue) malloc (sizeof(Queue));
    q->front = q->rear = createEmptyLink(NULL);
    q->size = 0;
    return q;
}

void enqueue(Queue* q, int it) {
    q->rear->next = createLink(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

int dequeue(Queue* q) {
    if (q->size == 0)
    {
        cout << "error" << "\n";
    }
    int it = q->front->next->element;
    q->front->next = q->front->next->next;
    if (q->front->next == NULL)
    {
        q->rear = q->front;
    }
    q->size--;
    return it;
}

int main() {

    Queue* q = createQueue();
    free(q);
    return 0;
}