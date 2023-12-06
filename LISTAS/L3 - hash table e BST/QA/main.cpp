#include<iostream>
using namespace std;

class Node {
public:
    bool ocup = false;
    string name;

    Node() {
        ocup = false;
    }

    void insert(string texto) {
        name = texto;
        ocup = true;
    }
};

class Dictionary {
private:
    int size;
    int cnt;
    Node *nodes;

public:
    Dictionary(int m) {
        size = m;
        cnt = 0;
        nodes = new Node[size];
    }

    void insert(string tex) {
        int chave = hashFunction(size, tex);  // Use the hashFunction from the first implementation
        int *hashmap = new int[20];
        bool inserir = true;
        hashmap[0] = chave;

        if (nodes[chave].ocup == true && nodes[hashmap[0]].name == tex) {
            inserir = false;
        }

        for (int i = 1; i < 20; i++) {
            hashmap[i] = (chave + i * i + 23 * i) % size;
            if (nodes[hashmap[i]].ocup == true && nodes[hashmap[i]].name == tex) {
                inserir = false;
            }
        }

        if (inserir) {
            for (int i = 0; i < 20; i++) {
                if (nodes[hashmap[i]].ocup == false && nodes[hashmap[i]].name != tex) {
                    nodes[hashmap[i]].insert(tex);
                    cnt++;
                    break;
                }
            }
        }
    }

    void remove(string tex) {
        int chave = hashFunction(size, tex);
        int *hashmap = new int[19];
        hashmap[0] = chave;
        for (int i = 1; i < 20; i++) {
            hashmap[i] = (chave + i * i + 23 * i) % size;
        }

        for (int i = 0; i < 20; i++) {
            if (nodes[hashmap[i]].ocup == true && nodes[hashmap[i]].name == tex) {
                nodes[hashmap[i]].ocup = false;
                nodes[hashmap[i]].name = "";
                cnt--;
                break;
            }
        }
    }

    void showtable() {
        cout << cnt << endl;
        for (int i = 0; i < size; i++) {
            if (nodes[i].ocup) {
                cout << i << ":" << nodes[i].name << endl;
            }
        }
    }

    int hashFunction(int m, string key) {
        int sum = 0;
        int size = key.length() + 1;
        for (int i = 1; i < size; i++) {
            char x = key.at(i - 1);
            sum = sum + int(x) * i;
        }
        int hash = (sum * 19) % m;
        return abs(hash);
    }
};

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int operations;
        cin >> operations;
        Dictionary dic = Dictionary(101);

        for (int j = 0; j < operations; j++) {
            string input;
            cin >> input;
            string command = input.substr(0, 4);
            string object = input.substr(4);

            if (command == "ADD:") {
                dic.insert(object);
            } else if (command == "DEL:") {
                dic.remove(object);
            }
        }
        dic.showtable();
    }

    return 0;
}
