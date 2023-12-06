// implementação de um grafo com lista de adjacência e toposort(dfs)

#include "bits/stdc++.h"

using namespace std;

typedef struct graph {
    vector<vector<int>> listAdj;
    int numEdge;
    vector<int>mark;
    int size;
}Graph;

Graph *createGraph(int n) {
    Graph *g = new Graph;

    g->listAdj.resize(n);
    g->mark.resize(n);

    g->numEdge = 0;
    g->size = n;

    return g;
}

void setEdge(Graph *g, int i, int j) {
    auto it = find(g->listAdj[i].begin(), g->listAdj[i].end(), j);
    auto it2 = find(g->listAdj[j].begin(), g->listAdj[j].end(), i);

    if (it == g->listAdj[i].end() and it2 == g->listAdj[j].end()) {
        g->numEdge++;
    }

    g->listAdj[i].push_back(j);
    g->listAdj[j].push_back(i);
}

void setMark(Graph *g, int v) {
    g->mark.push_back(v);
}

bool getMark(Graph *g, int v) {
    auto it = find(g->mark.begin(),g->mark.end(),v);
    if (it != g->mark.end()) {
        return true; // ele foi visitado
    }
}



