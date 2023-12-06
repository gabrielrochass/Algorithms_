//hash table implementation

#include "iostream"
using namespace std;

typedef struct entry {
    int key;
    int value;
}Entry;

typedef struct dictionary {
    int m; // array size
    int cnt; // number of elements
    Entry *h; // hash table
    int *perm; // collision method
}Dictionary;

Dictionary *createDictionary(int m) {
    Dictionary *d = (Dictionary*) malloc(sizeof(Dictionary));
    d->m = m;
    d->cnt = 0;
    return d;
}

int hashFuction(int m, int key) {
    return abs(key - (m * (key/m)));
}


int find(Dictionary *d, int key) {
    int position = hashFuction(d->m, key);
    if (d->h[position].key != NULL) {
        return position;
    } else {
        int aux = 0;
        while (d->h[position].key != NULL and aux < d->m - 1) {
            position = (position + d->perm[aux]) % d->m;
            if (d->h[position].key == key) {
                return position;
            }
            aux++;
        }
    }
    return -1;
}

void insert(Dictionary *d, int key, int value) {
    if (d->cnt < d->m and find(d, key) == -1) {
        int position = hashFuction(d->m, key);
        if (d->h[position].key != NULL) {
            int aux = 1;
            int offset = d->perm[aux-1];
            int newPosition = (position + offset) % d->m;
            while (d->h[newPosition].key != NULL) {
                aux++;
                offset = d->perm[aux-1];
                newPosition = (position + offset) % d->m;
            }
            position = newPosition;
        }
        d->h[position].key = key;
        d->h[position].value = value;
        d->cnt++;
    }
}

int main() {
    int permSize;
    cin >> permSize;

    while (permSize != 0) {
        int perm[permSize - 1];
        for (int i = 0; i < permSize-1; ++i) {
            cin >> perm[i];
        }

        int operations;
        cin >> operations;

        string command;
        int key, value;


        Dictionary *d = createDictionary(permSize);
        d->h = (Entry*) malloc(sizeof(Entry) * permSize);
        d->perm = perm;

        for (int j = 0; j < operations; ++j) {
            cin >> command;
            if (command == "add") {
                cin >> key >> value;
                insert(d, key, value);
            } else {
                cin >> key;
                int result = find(d, key);
                cout << result << endl;
            }
        }
        cin >> permSize;
    }
    return 0;
}

