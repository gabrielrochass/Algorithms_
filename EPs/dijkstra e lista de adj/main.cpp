#include "bits/stdc++.h"
using namespace std;

typedef struct g {
    vector<vector<pair<int, int>>> adjList;
    int numEdge;
    vector<int> mark;
    int size;
}G;

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

// grafo dirigido e ponderado
// s: vértice do grafo
// encontrar os caminhos de menor custo (MST) a partir de s (INCLUINDO O S)

// recebe numCases

// for com o numCases
// printa o caso
// recebe numVertex e numEdges

// for com o numEdges
// recebe v1, v2 e wt
// seta as arestas com o peso

// recebe o source (path`s begin)

// chamo dijkstra -> printa o caminho com endl
// se não for possível chegar em algum vértice (dist[source] == INT_MAX) -> cout << -1

int main() {
    int numCases, numVertex, numEdges, v1, v2, wt, source;
    cin >> numCases;

    for (int i = 0; i < numCases; i++)
    {
        cout << "Caso " << i + 1 << endl;
        cin >> numVertex >> numEdges;

        G *graph = createGraph(numVertex);
        vector<int> D(numVertex, INT_MAX);

        for (int j = 0; j < numEdges; j++)
        {
            cin >> v1 >> v2 >> wt;
            addEdge(graph, v1, v2, wt); // direcionado, então só tem indo (um de cada vez)
        }

        cin >> source;

        dijkstra(graph, source, D);


        for (int k = 0; k < numVertex; k++)
        {
            if (D[k] == INT_MAX) {
                cout << -1 << endl;
            } else if (D[k] == D[source]) {
                cout << 0 << endl;
            } else {
                cout << D[k] << endl;
            }
        }

        delete graph;
    }
    return 0;
}