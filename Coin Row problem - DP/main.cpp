#include "bits/stdc++.h"
using namespace std;

// coin row problem:
// O problema do "Coin Row" (ou "Problema da Fileira de Moedas") é um problema clássico de programação dinâmica (DP) que envolve uma fileira de moedas numeradas, cada uma com um valor associado.
//  O objetivo é encontrar a sequência de moedas a serem selecionadas de modo que a soma dos valores das moedas escolhidas seja maximizada, com a restrição de que você não pode selecionar moedas consecutivas na fileira.


// recebe numCases
// faz um for com o numCases
// recebe o size
// faz um for com o size
// recebe valores do vector
// chamo int result = coinRow() e couto
#include <iostream>
#include <vector>

using namespace std;

int coinRow(vector<int>& c, vector <int>& selectedCoins) {
    int n = c.size();
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        selectedCoins.push_back(c[0]);
        return c[0];
    }

    vector<int> f(n, 0);
    f[0] = c[0];
    f[1] = max(c[0], c[1]);

    for (int i = 2; i < n; i++) {
        f[i] = max(c[i] + f[i - 2], f[i - 1]);
    }

    int i = n - 1;
    while (i >= 0) {
        if (i == 0 or (i >= 2 and c[i] + f[i - 2] >= f[i - 1])) {
            selectedCoins.push_back(c[i]);
            i -= 2;
        } else {
            i -= 1;
        }
    }
    return f[n - 1];
}

int main() {
    int numCases, size, value, result;
    cin >> numCases;

    for (int i = 0; i < numCases; ++i) {
        cin >> size;
        vector<int> c(size);
        vector<int> selectedCoins;

        for (int j = 0; j < size; ++j) {
            cin >> value;
            c[j] = value;
        }

        result = coinRow(c, selectedCoins);
        cout << result << endl;

        for (int j = 0; j < selectedCoins.size(); ++j) {
            cout << selectedCoins[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
