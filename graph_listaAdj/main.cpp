// graph implementation with adj list
#include "bits/stdc++.h"

using namespace std;
#define endl "\n"

typedef pair<int, int>ii; // <vertice, peso>

typedef struct graph {
    vector<vector<int>> coluna; // coluna
    vector<vector<ii>> ligados; // pair <está ligado a quem, qual o peso>
    int numEdge; // num de arestas
    int size; // tamanho inicial do grafo (coluna principal antes de adicionar as arestas - conexões)
    vector<int>mark; // vetor de marcados
}Graph;

Graph  *createGraph(int size) {
    Graph *g = new Graph; // alocação de memória para o grafo

    g->coluna.resize(size); // seta a coluna
    g->mark.resize(size); // seta vetor de marcados

    g->size = size; // separa o tamanho do grafo
    g->numEdge = 0; // separa o número de arestas

    return g; // retorna o grafo
}

// rodar first e next em um for

void setEdge(Graph *g, int i, int j) {
    g->coluna[i].push_back(j);
    g->coluna[j].push_back(i); // não direcionado
//    g->ligados[5].push_back({7,3});
}

void bfs(Graph *g, int vertice) {


}


int main() {
    int vertices, operations;
    cin >> vertices >> operations;
    Graph *g = createGraph(vertices);

    string command;
    cin >> command;

    for (int i = 0; i < operations; i++)
    {
        if (command == "add") {
            int v1, v2;
            cin >> v1 >> v2;
            setEdge(g, v1, v2, 1);
            setEdge(g, v2, v1, 1);

//        } else if (command == "BFS") {
//            int v;
//            cin >> v;
////            BSF(g, v);
//            graphTraverseBFS(g, v);
//            cout << endl;
        } else if (command == "DFS") {
            int v;
            cin >> v;
//            DSF(g, v);
            graphTraverseDfs(g, v);
            cout << endl;
        }

        cin >> command;
    }


    return 0;
}
