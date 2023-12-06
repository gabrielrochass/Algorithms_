#include <iostream>
using namespace std;

typedef struct link {
    int element;
    link* next;
} Link;

typedef struct stack {
    Link *top;
    int size;
} Stack;

Link *createLink(int newElement, Link *newNext) {
    Link* n = new Link;
    n->element = newElement;
    n->next = newNext;
    return n;
}

Stack *createStack() {
    Stack *s = new Stack;
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack* s, int it) {
    s->top = createLink(it, s->top);
    s->size++;
}

int pop(Stack* s) {
    if (s->top != NULL) {
        int it = s->top->element;
        Link* temp = s->top;
        s->top = s->top->next;
        delete temp;
        s->size--;
        return it;
    }
    return -1;
}

int main() {
    while (true) {
        int num;
        cin >> num;

        if (num == 0)
            break;

        while (true) {
            int arr[num];
            cin >> arr[0];

            if (arr[0] == 0) {
                cout << endl;
                break;
            }

            for (int i = 1; i < num; ++i) {
                cin >> arr[i];
            }

            Stack *s = createStack();
            int x = 0;
            bool possible = true;

            for (int i = 1; i <= num; ++i) {
                push(s, i);
                while (!s->top == NULL && s->top->element == arr[x]) {
                    pop(s);
                    x++;
                }
            }

            if (!s->top) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }

            delete s;
        }
    }

    return 0;
}
