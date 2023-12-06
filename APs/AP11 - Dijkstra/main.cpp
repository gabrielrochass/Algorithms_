#include <bits/stdc++.h>
using namespace std;

const int UNVISITED = 0;
const int VISITED = 1;

typedef struct g {
    vector<vector<int>> matrix;
    int numEdge;
    vector<int> mark;
    int size;
} G;

G *createGraph(int n) {
    G *graph = new G;
    graph->mark.resize(n);
    graph->matrix.assign(n, vector<int>(n, 0));
    graph->numEdge = 0;
    graph->size = n;
    return graph;
}

int first(G *graph, int vertex) {
    for (int i = 0; i < graph->size; ++i) {
        if (graph->matrix[vertex][i] != 0) {
            return i;
        }
    }
    return graph->size;
}

int next(G *graph, int vertex, int nextVertex) {
    for (int i = nextVertex + 1; i < graph->size; ++i) {
        if (graph->matrix[vertex][i] != 0) {
            return i;
        }
    }
    return graph->size;
}

void setMark(G *graph, int vertex, int value) {
    graph->mark[vertex] = value; // visited == 1; unvisited == 0
}

int getMark(G *graph, int vertex) {
    return graph->mark[vertex];
}

int weight(G *graph, int v1, int v2) {
    return graph->matrix[v1][v2];
}

void dijkstra(G *graph, int source, vector<int> &D) {
    for (int i = 0; i < graph->size; ++i) {
        D[i] = INT_MAX;
        setMark(graph, i, UNVISITED);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push(make_pair(0, source));
    D[source] = 0;

    while (!heap.empty()) {
        pair<int, int> current = heap.top();
        heap.pop();

        int distance = current.first;
        int vertex = current.second;

        if (getMark(graph, vertex) == VISITED) {
            continue;
        }

        setMark(graph, vertex, VISITED);

        int w = first(graph, vertex);
        while (w < graph->size) {
            if (getMark(graph, w) != VISITED && D[w] > D[vertex] + weight(graph, vertex, w)) {
                D[w] = D[vertex] + weight(graph, vertex, w);
                heap.push(make_pair(D[w], w));
            }
            w = next(graph, vertex, w);
        }
    }
}

int main() {
    int numVertex, numEdges, source, v1, v2, wt;
    cin >> numVertex >> numEdges >> source;

    G *graph = createGraph(numVertex);
    vector<int> D(numVertex, INT_MAX);

    for (int i = 0; i < numEdges; ++i) {
        cin >> v1 >> v2 >> wt;
        graph->matrix[v1][v2] = wt;
        graph->matrix[v2][v1] = wt;
    }

    dijkstra(graph, source, D);

    for (int j = 0; j < numVertex; ++j) {
        if (D[j] == INT_MAX) {
            cout << -1 << " ";
        } else if (j == source) {
            cout << 0 << " ";
        } else {
            cout << D[j] << " ";
        }
    }
    cout << endl;

    return 0;
}
