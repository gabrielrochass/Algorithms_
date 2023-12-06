#include <bits/stdc++.h>
using namespace std;

int knapsack(int numItems, int capacity, vector<int>& w, vector<int>& v, vector<vector<int>>& F) {
    for (int i = 0; i <= numItems; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            if (i == 0 or j == 0) {
                F[i][j] = 0;
            } else if (w[i] <= j) {
                F[i][j] = max(F[i - 1][j], v[i] + F[i - 1][j - w[i]]);
            } else {
                F[i][j] = F[i - 1][j];
            }
        }
    }
    return F[numItems][capacity];
}

// recebe capacity e numItems
// for com numItems
// pra cada linha: recebe peso e dá pushback em w, recebe valor e dá pushback em v
// inicializa a matriz toda com -1
// inializa a primeira linha e primeira coluna com 0
// chama o resultado


int main() {
    int capacity, numItems;
    cin >> capacity >> numItems;

    vector<int> w(numItems + 1);
    vector<int> v(numItems + 1);
    vector<vector<int>> F(numItems + 1, vector<int>(capacity + 1, -1));

    for (int i = 1; i <= numItems; ++i) {
        cin >> w[i] >> v[i];
    }

    int result = knapsack(numItems, capacity, w, v, F);
    cout << result;

    return 0;
}
