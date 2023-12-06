#include "bits/stdc++.h"

using namespace std;

int main() {
    int numVertex, numEdges, source;
    while (cin >> numVertex >> numEdges >> source and numVertex) {
        vector< vector< pair<int, int> > > graph(numVertex); // cria o grafo como uma lista de vector (adjacência)
        // o grafo vai ser do formato:
        // 0: (1, 3) -> o vértice 0 se conecta ao grafo 1 com peso 3

        for (int i = 0; i < numEdges; ++i) {
            int v1, v2, cost;
            cin >> v1 >> v2 >> cost;
            graph[v1].push_back({v2, cost});
            graph[v2].push_back({v1, cost});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; // cria a heap minima
        vector<bool> mark(numVertex, false); // seta todo mundo como não visitado

        mark[source] = true; // visitado
        for (pair<int, int> edge : graph[source]) { // coloca todos os viznhos do vertice na heap
            heap.push({edge.second, edge.first});
        }

        int sum = 0; // total cost
        while (heap.size()) {
            pair <int, int> menor = heap.top();
            heap.pop();

            if (mark[menor.second] == true) continue;

            sum += menor.first;
            mark[menor.second] = true;
            for (pair<int, int> edge : graph[menor.second]) {
                heap.push({edge.second, edge.first});
            }
        }
        cout << sum << endl;
    }


    return 0;
}

/*
 input:
 6 8 0
0 1 350
1 2 180
0 3 270
3 4 200
4 5 300
1 4 190
3 5 500
2 5 400
7 11 0
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0

 output:
 1140
39
 */