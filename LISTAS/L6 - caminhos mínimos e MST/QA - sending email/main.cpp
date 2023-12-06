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

void addEdge(G *g, int i, int j, int wt) {
    g->adjList[i].push_back(make_pair(j, wt));
}

int weight(G *graph, int v1, int v2) {
    for (int i = 0; i < graph->adjList[v1].size(); ++i) {
        int w = graph->adjList[v1][i].first;
        int wt = graph->adjList[v1][i].second;
        if (w == v2) {
            return wt;
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

void dijkstra(G *graph, int source, vector<int> &distance) {
    for (int i = 0; i < graph->size; ++i) {
        distance[i] = INT_MAX;
        setMark(graph, i, 0);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push(make_pair(0, source));
    distance[source] = 0;

    while (!heap.empty()) {
        pair<int, int> current = heap.top();
        heap.pop();

        int vertex = current.second;

        if (getMark(graph, vertex) == 1) continue;

        setMark(graph, vertex, 1);

        for (int i = 0; i < graph->adjList[vertex].size(); ++i) {
            int w = graph->adjList[vertex][i].first;
            int wt = graph->adjList[vertex][i].second;
            if (distance[w] > distance[vertex] + wt) {
                distance[w] = distance[vertex] + wt;
                heap.push(make_pair(distance[w], w));
            }
        }
    }
}


//grafo não direcionado -> setar indo e vindo!!
// n servers
// m cables
// s servers source
// t server destination

// recebe numCases
// for com numCases
// recebe numServers, numEdge, v1, v2


int main() {
    int numCases, numVertex, numEdges, source, destination, v1, v2, wt;
    cin >> numCases;

    for (int i = 0; i < numCases; ++i) {
        cout << "Case #" << i + 1 << ": ";
        cin >> numVertex >> numEdges >> source >> destination;

        G *graph = createGraph(numVertex);
        vector<int> D(numVertex, INT_MAX);

        for (int j = 0; j < numEdges; ++j) {
            cin >> v1 >> v2 >> wt;
            addEdge(graph, v1, v2, wt);
            addEdge(graph, v2, v1, wt);
        }

        dijkstra(graph, source, D);

        if (D[destination] == INT_MAX) {
            cout << "unreachable" << endl;
        } else if (D[destination] == D[source]) {
            cout << 0 << endl;
        } else {
            cout << D[destination] << endl;
        }

        delete graph;
    }

    return 0;
}
