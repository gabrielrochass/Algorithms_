#include <bits/stdc++.h>

using namespace std;

typedef struct g {
    vector<vector<int>> adj;
    vector<int> numEdges;
    int size;
} G;

G* createGraph(int n) {
    G* g = new G;
    g->adj.resize(n);
    g->numEdges.resize(n, 0);
    g->size = n;
    return g;
}

void addEdge(G* g, int x, int y) {
    g->adj[x].push_back(y);
    g->numEdges[y]++;
}

vector<int> topologicalSort(G* g) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < g->size; ++i) {
        if (g->numEdges[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);

        for (int v : g->adj[u]) {
            g->numEdges[v]--;
            if (g->numEdges[v] == 0) {
                pq.push(v);
            }
        }
    }

    return result;
}

int main() {
    int size, numCases, job1, job2;
    cin >> size >> numCases;
    G* g = createGraph(size);

    for (int i = 0; i < numCases; ++i) {
        cin >> job1 >> job2;
        addEdge(g, job1 - 1, job2 - 1);
    }

    vector<int> result = topologicalSort(g);

    if (result.size() != size) {
        cout << "Sandro fails." << endl;
    } else {
        for (int i = 0; i < size; ++i) {
            cout << result[i] + 1 << " ";
        }
    }

    return 0;
}
