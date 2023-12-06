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
    g->matrix[j][i] = wt; // undirected graphs
}

void delEdge(G *g, int i, int j) {
    if (g->matrix[i][j] != 0) {
        g->numEdge--;
    }
    g->matrix[i][j] = 0;
}

void setMark(G *g, int v, int value) {
    g->mark[v] = value;
}

int getMark(G *g, int v) {
    return g->mark[v];
}

void bfsShortestPath(G *g, int start, int destination) {
    queue<int> q;
    q.push(start);
    setMark(g, start, 1);

    vector<int> predecessor(g->size, -1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == destination) {
            return;
        }

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
        cout << "No path found from " << start << " to " << destination << endl;
    } else {
        cout << "Shortest path from " << start << " to " << destination << ": ";
        vector<int> path;
        int current = destination;
        while (current != -1) {
            path.push_back(current);
            current = predecessor[current];
        }
        reverse(path.begin(), path.end());
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
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

int main() {
    G *g = createGraph(6);

    //int v0, v1, v2, v3, v4, v5;
    setEdge(g, 0, 2, 1);
    setEdge(g, 0, 4, 1);

    setEdge(g, 1, 2, 1);
    setEdge(g, 1, 5, 1);

    setEdge(g, 2, 3, 1);
    setEdge(g, 2, 1, 1);
    setEdge(g, 2, 5, 1);
    setEdge(g, 2, 0, 1);

    setEdge(g, 3, 2, 1);
    setEdge(g, 3, 5, 1);

    setEdge(g, 4, 0, 1);
    setEdge(g, 4, 5, 1);

    setEdge(g, 5, 1, 1);
    setEdge(g, 5, 2, 1);
    setEdge(g, 5, 3, 1);
    setEdge(g, 5, 4, 1);


    graphTraverseBfs(g, 0, 4);

    return 0;
}
