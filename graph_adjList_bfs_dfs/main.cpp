#include "bits/stdc++.h"
using namespace std;

typedef struct g {
    vector<vector<pair<int, int>>> adjList;
    int numEdge;
    vector<int> mark;
    int size;
} G;

G *createGraph(int numVertex) {
    G *graph = new G;
    graph->mark.resize(numVertex);
    graph->adjList.resize(numVertex);
    graph->numEdge = 0;
    graph->size = numVertex;
    return graph;
}

void setEdge(G *g, int i, int j, int wt) {
    g->adjList[i].push_back(make_pair(j, wt));
}

int weight(G *graph, int v1, int v2) {
    for (auto edge : graph->adjList[v1]) {
        if (edge.first == v2) {
            return edge.second;
        }
    }
    return 0;
}

void setMark(G *graph, int vertex, int value) {
    graph->mark[vertex] = value;
}

int getMark(G *graph, int vertex) {
    return graph->mark[vertex];
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
    int w = first(g, v); // adaptar fir

    while (w < g->size) {
        if (getMark(g, v) == 0) {
            dfs(g, w);
        }
        w = next(g, v, w); // adaptar first e next
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