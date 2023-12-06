#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


typedef struct g
{
    int **matrix;
    int numEdge;
    int *mark;
    int size;
}G;

G *createGraph(int n) {
    G *g = new G;
    g->mark = new int[n];
    g->matrix = new int*[n];

    for (int i = 0; i < n; i++)
    {
        g->matrix[i] = new int[n];
    }

    g->numEdge = 0;
    g->size = n;

    return g;

}


int first(G *g, int v) { // retorna o primeiro vertice q v se conecta
    for (int i = 0; i < g->size; i++)
    {
        if (g->matrix[v][i] != 0) {
            return i;
        }

    }
    return g->size;

}

int next(G *g, int v, int w) { // retorna o primeiro vertice q v se liga depois de w
    for (int i = w + 1; i < g->size; i++)
    {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->size; // ausencia de aresta
}




void setEdge(G *g, int i, int j, int wt) {
    if (wt == 0) {
        return; // ausencia de aresta (erro)
    }
    if (g->matrix[i][j] == 0)
    {
        g->numEdge++;
    }

    g->matrix[i][j] = wt; // atualiza o peso
}


void setMark(G *g, int v, int value) {
    g->mark[v] = value;

}

int getMark(G *g, int v) {
    return g->mark[v];

}

void DFS(G *g, int v) { // profundidade
    cout << v << " "; // previsit
    setMark(g, v, 1);

    int w = first(g, v);
    while (w < g->size)
    {
        if (getMark(g, w) == 0) {
            DFS(g, w);
        }
        w = next(g, v, w);
    }

}

void BFS(G *g, int start) {
    queue<int> q;
    q.push(start);
    setMark(g, start, 1);

    while (q.size() > 0)
    {
        int v = q.front();
        q.pop();
        cout << v << " "; // previsit

        int w = first(g, v);
        while (w < g->size)
        {
            if (getMark(g, w) == 0)
            {
                setMark(g, w, 1);
                q.push(w);
            }
            w = next(g, v, w);
        }
    }
}

void graphTraverseDFS(G *g, int v) {
    for (int j = 0; j < g->size; j++)
    {
        setMark(g, j, 0); // seta todos os vertices como 0
    }

    DFS(g, v);

    for (int i = 0; i < g->size; i++) // também pega vertices não conectados
    {
        if (getMark(g, i) == 0) {
            DFS(g, i); // inicia a travessia de todos os vertices não visitados
        }
    }

}

void graphTraverseBFS(G *g, int v) {
    for (int j = 0; j < g->size; j++)
    {
        setMark(g, j, 0); // seta todo mundo pra 0
    }

    for (int i = v; i < g->size; i++)
    {
        if (getMark(g, i) == 0) {
            BFS(g, i); // chama bfs pra todo vértice não visitado a partir do vértice q ele quer
        }
    }

}



// não dirigido: 3 <-> 2
// não ponderado: BSF ou dfs

// n: qt vértices
// q: qt operações (for i in range q)

// add u v: add uma aresta entre u e v E entre v e u (não dirigido)
// bsf v
// dsf v

int main() {


    // cria o grafo
    //recebe a qt de vertices e o numero de operações
    // loop para realizar operações
    //verifica a string de comando
    //realiza operação



    int vertices, operations;
    cin >> vertices >> operations;
    G *g = createGraph(vertices);

    string command;
    cin >> command;

    for (int i = 0; i < operations; i++)
    {
        if (command == "add") {
            int v1, v2;
            cin >> v1 >> v2;
            setEdge(g, v1, v2, 1);
            setEdge(g, v2, v1, 1);

        } else if (command == "BFS") {
            int v;
            cin >> v;
//            BSF(g, v);
            graphTraverseBFS(g, v);
            cout << endl;
        } else if (command == "DFS") {
            int v;
            cin >> v;
//            DSF(g, v);
            graphTraverseDFS(g, v);
            cout << endl;
        }

        cin >> command;
    }


    return 0;
}
