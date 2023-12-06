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
