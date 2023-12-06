// shortest path with bfs

#include "bits/stdc++.h"

using namespace std;

typedef struct g {
  int **matrix;
  int numEdge;
  int *mark;
  int size;
}G;

G *createGraph(int n) {
    G *g = new G;
    g->mark = new int[n];
    g->matrix = new int*[n];

    for (int i = 0; i < n; ++i) {
        g->matrix[i] = new int[n];
    }

    g->numEdge = 0;
    g->size = n;
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

void bfs(G *g, int start) {
    queue<int>q;
    q.push(start);
    setMark(g, start, 1);

    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        int w = first(g, v);
        while (w < g->size) {
            if (getMark(g,w) == 0) {
                setMark(g, w, 1);
                q.push(w);
            }
            w = next(g, v, w);
        }
    }
}

void graphTraverseBfs(G *g, int v) {
    for (int i = 0; i < g->size; ++i) {
        setMark(g, i, 0);
    }

    for (int j = v; j < g->size; ++j) {
        if (getMark(g, v) == 0) {
            bfs(g, v);
        }
    }
}

void dfs(G *g, int v) {
    cout << v << " ";
    setMark(g, v, 1);
    int w = first(g, v);

    while (w < g->size) {
        if (getMark(g, v) == 0) {
            dfs(g, w);
        }
        w = next(g, v, w);
    }
}

void graphTraverseDfs(G *g, int v) {
    for (int i = 0; i < g->size; ++i) {
        setMark(g,i, 0);
    }

    dfs(g, v);

    for (int i = 0; i < g->size; ++i) {
        if (getMark(g,i) == 0) {
            dfs(g, i);
        }
    }
}