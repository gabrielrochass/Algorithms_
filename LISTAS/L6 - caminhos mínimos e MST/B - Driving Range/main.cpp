#include <bits/stdc++.h>

using namespace std;

int main() {
    int numVertex, numEdges;
    while (cin >> numVertex >> numEdges && numVertex) {
        vector<vector<pair<int, int>>> graph(numVertex);// cria o grafo como uma lista de vector (adjacência)
        // o grafo vai ser do formato:
        // 0: (1, 3) -> o vértice 0 se conecta ao grafo 1 com peso 3

        for (int i = 0; i < numEdges; ++i) {
            int v1, v2, cost;
            cin >> v1 >> v2 >> cost;
            graph[v1].push_back({v2, cost});
            graph[v2].push_back({v1, cost}); // seta arestas
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;// cria a heap min
        vector<bool> mark(numVertex, false);// seta todo mundo como não visitado

        mark[0] = true; // visitado
        for (pair<int, int> edge : graph[0]) { // coloca todos os viznhos do vertice na heap
            heap.push({edge.second, edge.first});
        }

        int maxCost = 0;

        while (heap.size()) {
            pair<int, int> smallest = heap.top();
            heap.pop();

            if (mark[smallest.second]) continue;

            maxCost = max(maxCost, smallest.first);

            mark[smallest.second] = true;

            for (pair<int, int> edge : graph[smallest.second]) {
                heap.push({edge.second, edge.first});
            }
        }

        bool isPossible = true;

        for (int i = 0; i < numVertex; ++i) {
            if (!mark[i]) {
                isPossible = false;
                break;
            }
        }

        if (isPossible) {
            cout << maxCost << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
