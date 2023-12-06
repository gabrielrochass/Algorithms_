#include <iostream>
using namespace std;

typedef struct link
{
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

void insert(List *l, int element) {
    l->curr->next = createLink(element, l->curr->next);
    if (l->tail == l->curr) {
        l->tail = l->curr->next;
        l->cnt++;
    }
}

void moveToStart(List *l) {
    l->curr = l->head;
}

void prev(List *l) {
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
    if (l->curr->next == NULL) {
        return NULL;
    }
    int it = l->curr->next->element;
    if (l->tail == l->curr->next) {
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->cnt--;
    return it;
}


int main(){
    List *l;
    l = createList();
    int cases;
    cin >> cases;
    int operations;
    cin >> operations;
    string command;
    int num;

    for (int i = 0; i < cases; ++i) {
        cout << "Caso " << i + 1 << ":" << endl;

        for (int j = 0; j < operations; ++j) {
            cin >> command;
            if(command == "insert" or command == "count") {
                cin >> num;
            }
            if (command == "insert") {
                insert(l, num);
            } else if (command == "remove") {
                remove(l);
            } else if (command == "count") {
                int contador = 0;
                Link *temp = l->curr;
                moveToStart(l);
                while (l->curr->next != NULL) {
                    if (l->curr->next->element == num) {
                        contador++;
                    }
                    next(l);
                }
                l->curr = temp;
                cout << contador << "\n";
            } else if (command == "next") {
                next(l);
            }
        }

    }
}