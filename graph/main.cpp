#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


typedef struct g
{
    int **matrix;
    int numEdge;
    int *mark;
    int size;
}G;

G *createGraph(int n) {
    G *g = new G;
    g->mark = new int[n];
    g->matrix = new int*[n];

    for (int i = 0; i < n; i++)
    {
        g->matrix = new int*[n];
    }

    g->numEdge = 0;
    int size = n;

    return g;

}


int first(G *g, int v) {
    for (int i = 0; i < g->size; i++)
    {
        if (g->matrix[v][i] != 0) {
            return i;
        }

    }
    return g->size;

}

int next(G *g, int v, int w) {
    for (int i = w + 1; i < g->size; i++)
    {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->size;
}




void setEdge(G *g, int i, int j, int wt) {
    if (wt = 0) {
        return;
    }
    if (g->matrix[i][j] == 0)
    {
        g->numEdge++;
    }

    g->matrix[i][j] = wt;
}

void delEdge(G *g, int i,int j) {
    if (g->matrix[i][j] != 0)
    {
        g->numEdge--;
    }

    g->matrix[i][j] = 0;
}

void setMark(G *g, int v, int value) {
    g->mark[v] = value;

}

int getMark(G *g, int v) {
    int result = g->mark[v];
    return result;
}

void visit(G *g, int v) {
    cout << v << endl;
}


void DFS(G *g, int v) {
    // preVisit(g, v);
    // cout << v << endl;
    visit(g, v);
    setMark(g, v, 1);

    int w = first(g, v);
    while (w < g->size)
    {
        if (getMark(g, w) == 0) DFS(g, w);
        w = next(g, v, w);
    }


    // posVisit(g, v)
    visit(g, v);

}

void BFS(G *g, int start) {
    queue<int> q;
    q.push(start);
    setMark(g, start, 1);

    while (q.size() > 0)
    {
        int v = q.front();
        q.pop();
        visit(g, v);

        int w = first(g, v);
        while (w < g->size)
        {
            if (getMark(g, w) == 0)
            {
                setMark(g, w, 1);
                q.push(w);
            }
            w = next(g, v, w);

        }
        visit(g, v);
    }

}

void graphTraverse(G *g) {
    for (int v = 0; v < g->size; v++)
    {
        setMark(g, v, 0);
    }

    for (int i = 0; i < g->size; i++)
    {
        if (getMark(g, i)) DFS(g, i);
    }

}