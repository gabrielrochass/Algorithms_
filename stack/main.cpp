//implementing stack
//linked list + stack

#include "iostream"

using namespace std;

typedef struct link {
    int element;
    link* next;
}Link;

Link *createLink(int newElement, Link *newNext) {
    Link* n = (Link*) malloc (sizeof(Link));
    n->element = newElement;
    n->next = newNext;
    return n;
}

Link *createEmptyLink(Link *newNext) {
    Link* n = (Link*) malloc (sizeof(Link));
    n->next = newNext;
    return n;
}

typedef struct list {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
}List;

List *createList() {
    List *l = (List*) malloc (sizeof(List));
    l->curr = l->tail = l->head = createEmptyLink(NULL);
    l->cnt = 0;
    return l;
}

void insert(List* l, int it) {
    l->curr->next = createLink(it, l->curr->next);
    if (l->tail == l->curr) {
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void moveToStart(List* l) {
    l->curr = l->head;
}

void prev(List* l) {
    if (l->curr == l->head) {
        return;
    }
    Link* temp = l->head;
    while (temp->next != l->curr) {
        temp = temp->next;
    }
    l->curr = temp;
}

void next(List* l) {
    if (l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}

int remove(List* l) {
    if(l->curr->next == NULL) {
        return NULL;
    }
    int it = l->curr->next->element;
    if (l->tail == l->curr->next) {
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    return it;
}

typedef struct stack {
    Link* top;
    int size;
}Stack;

Stack *createStack() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack* s, int it) {
    s->top = createLink(it, s->top);
    s->size++;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        cout << "error" << endl;
    }
    int it = s->top->element;
    s->top = s->top->next;
    s->size--;
    return it;
}


int main() {

//    List *l;
//    l = createList()
    Stack *s;
    s = createStack();

    int cases;
    cin >> cases;

    string command;
    int num;
    cin >> command;

    for (int i = 0; i < cases; ++i) {
        cout << "Caso " << i+1 << ":\n";
        while (command != "end") {
            int soma = 0;
            cin >> num;
            if (command == "push") {
                push(s, num);
            } else if (command == "pop") {
                for (int j = 0; j < num; ++j) {
                    soma = soma + pop(s);
                }
                cout << soma << "\n";
            }
            cin >> command;
        }
    }


    return 0;
}

