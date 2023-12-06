#include "bits/stdc++.h"

using namespace std;

typedef struct g {
    int **matrix;
    int numEdge;
    int *mark;
    int size;
} G;

G *createGraph(int n) {
    G *g = new G;
    g->mark = new int[n];
    g->matrix = new int *[n];

    for (int i = 0; i < n; ++i) {
        g->matrix[i] = new int[n];
    }

    g->numEdge = 0;
    g->size = n;

    return g;
}

int first(G *g, int v) {
    for (int i = 0; i < g->size; ++i) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->size;
}

int next(G *g, int v, int w) {
    for (int i = w + 1; i < g->size; ++i) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->size;
}

void setEdge(G *g, int i, int j, int wt) {
    if (wt == 0) {
        return;
    }
    if (g->matrix[i][j] == 0) {
        g->numEdge++;
    }
    g->matrix[i][j] = wt;
}

void setMark(G *g, int v, int value) {
    g->mark[v] = value;
}

int getMark(G *g, int v) {
    return g->mark[v];
}

void bfsShortestPath(G *g, int start, int destination) {
    if (start == destination) {
        cout << 0 << endl;
        return;
    }
    queue<int> q;
    q.push(start);
    setMark(g, start, 1);

    vector<int> predecessor(g->size, -1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        int w = first(g, v);
        while (w < g->size) {
            if (getMark(g, w) == 0) {
                setMark(g, w, 1);
                q.push(w);
                predecessor[w] = v;
            }
            w = next(g, v, w);
        }
    }

    if (predecessor[destination] == -1) {
        cout << "-1" << endl;
    } else {
        vector<int> path;
        int current = destination;

        while (current != -1) {
            path.push_back(current);
            current = predecessor[current];
        }

        int counter;
        for (int vertex : path) {
            counter++;
        }

        cout << counter - 1 << endl;
    }
}

void graphTraverseBfs(G *g, int v, int d) {
    for (int i = 0; i < g->size; ++i) {
        setMark(g, i, 0);
    }


    for (int j = v; j < g->size; ++j) {
        if (getMark(g, v) == 0) {
            bfsShortestPath(g, v, d);
        }
    }
}



// grafo dirigido não ponderado
// find the shortest path (BFS)

//recebe a quantidade de casos
//for na quantidade de casos
// recebe o numero de vertices
// recebe o numero de arestas
// for com o numero de arestas
// seta as arestas
// recebe o numero de perguntas
// for com o numero de perguntas
// menor caminho entre as arestas dadas
// acaba o for -> volta pro início

// não imprimir o caminho, imprimir a menor quantidade de arestas(contador de vector?)
// se não tiver caminho, imprimir -1

// consertar quando n tiver caminho

int main() {
    int numCases, numVertex, numEdge, v1, v2, numQuestions, begin, end;
    cin >> numCases;

    for (int i = 0; i < numCases; i++) {
        cin >> numVertex >> numEdge;
        G *g = createGraph(numVertex); // verificar se crio dentro do for
        cout << "Caso " << i + 1 << endl;

        for (int j = 0; j < numEdge; j++) {
            cin >> v1 >> v2;
            setEdge(g, v1, v2, 1);
        }

        cin >> numQuestions;
        for (int k = 0; k < numQuestions; k++) {
            cin >> begin >> end;
            graphTraverseBfs(g, begin, end);
        }
    }

    return 0;
}
