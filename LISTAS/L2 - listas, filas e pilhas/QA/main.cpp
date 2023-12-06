#include <iostream>
using namespace std;

typedef struct link
{
    char element;
    link* next;
}Link;

Link *createLink(int newElement, Link *newNext) {
    Link* n = (Link*) malloc (sizeof(Link));
    n->element = newElement;
    n->next = newNext;
    return n;
}

Link *createEmptyLink(Link *newNext) {
    Link *n = (Link*) malloc (sizeof(Link));
    n->next = newNext;
    return n;
}

typedef struct list
{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt; // listSize
}List;

List *createList() {
    List *l = (List*) malloc (sizeof(List)); //aloca
    l->curr = l->tail = l->head = createEmptyLink(NULL); //header node
    l->cnt = 0;
    return l;
}

void insert(List *l, char element) {
    l->curr->next = createLink(element, l->curr->next);
    if (l->tail == l->curr) {
        l->tail = l->curr->next;
        l->cnt++;
    }
}

void moveToStart(List *l) {
    l->curr = l->head;
}

void moveToEnd(List* l) {
    l->curr = l->tail;
}


void next(List* l) {
    if (l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}

void printList(List *l, int cnt) {
    moveToStart(l);
    for (int i = 0; i < cnt; ++i) {
        if (l->curr->next != NULL) {
            cout << l->curr->next->element;
        }
        next(l);
    }
    cout << endl;
}

int main() {
    string enter;
    int count = 0;

    while (cin >> enter) {
        List *l;
        l = createList();
        for (int i = 0; i < enter.size(); ++i) {
            char chr = enter[i];

            if ((chr != '[') and (chr != ']')) {
                insert(l,chr);
                next(l);
            } else if (chr == '[') {
                moveToStart(l);
            } else {
                moveToEnd(l);
            }
            count++;
        }
        printList(l, count);
    }

    return 0;
}