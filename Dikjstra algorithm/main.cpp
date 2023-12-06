#include "bits/stdc++.h"
using namespace std;

const int UNVISITED = 0;
const int VISITED = 1;

typedef struct g{
  vector<vector<int>> matrix;
  int numEdge;
  vector<int> mark;
  int size;
}G;

G *createGraph(int numVertex) {
    G *graph = new G;
    graph->mark.resize(numVertex); // redimensiona o vector de marcados parar garantir que haja espaço de marcar cada vértice como visited ou unvisited
    graph->matrix.assign(numVertex, vector<int>(numVertex, 0)); // inicializando todos os elementos da matriz como zero (inicialmente, não há arestas entre nenhum dos vértices)
    graph->numEdge = 0;
    graph->size = numVertex;
    return graph;
}

int first(G *graph, int vertex) { // retorna o primeiro vertex que o vertex de origem se conecta
    for (int i = 0; i < graph->size; ++i) {
        if (graph->matrix[vertex][i] != 0) return i;
    }
    return graph->size;
}

int next(G *graph, int vertex, int nextVertex) { // retorna o próximo vertex que o vertex se conecta depois do first
    for (int i = nextVertex + 1; i < graph->size; ++i) {
        if (graph->matrix[vertex][i] != 0) return i;
    }
    return graph->size;
}

void setMark(G *graph, int vertex, int value) { // mark as visited or unvisited
    graph->mark[vertex] = value;
}

int getMark(G *graph, int vertex) { // return if it is visited or unvisited
    return graph->mark[vertex];
}

int weight(G *graph, int v1, int v2) { // return the weight between v1 and v2
    return graph->matrix[v1][v2];
}

void dijkstra(G *graph, int source, vector<int> &distance) { //&distance: vector de distâncias mínimas passado como referência de um valor, ou seja, altera o valor original do vector, sem tratar de uma cópia
    for (int i = 0; i < graph->size; ++i) {
        distance[i] = INT_MAX; // set all distances to infinite (INT_MAX: maior valor de int em cpp)
        setMark(graph, i, UNVISITED); // set all vertexes as unvisited
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; // inicializa uma heap min com pares de inteiros do tipo (distância acumulada, vértice de destino). Não uso uma tripla pq o vértice de origem se mantém o mesmo se pensar de forma cumulativa
    heap.push(make_pair(0, source)); // (S,S,0)
    distance[source] = 0;

    while (!heap.empty()) {
        pair<int, int> current = heap.top(); // pega o elemento de maior prioridade (menor distancia -> primeiro do pair)
        heap.pop(); // remove o elemento de maior prioridade -> processando ele

        int distPlus = current.first; // extrai a distancia acumulada se precisar
        int vertex = current.second;

        if (getMark(graph, vertex) == VISITED) continue; // se o vertex já foi visitado, o loop pula para a próxima iteração sem execultar o resto do código

        setMark(graph, vertex, VISITED); // se ele chega aqui é pq n foi visitado, então marco como visitado
        int w = first(graph, vertex); // pega o primeiro vertice adjacente a vertex

        while (w < graph->size) { // itera pelos adjacentes enquanto houver vértices a serem explorados
            if (getMark(graph,w) != VISITED and distance[w] > distance[vertex] + weight(graph, vertex, w)) {
                distance[w] = distance[vertex] + weight(graph, vertex, w);
                heap.push(make_pair(distance[w], w));
            }
            w = next(graph, vertex, w);
        }
    }
}