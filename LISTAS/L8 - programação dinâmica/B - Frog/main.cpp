#include <bits/stdc++.h>
using namespace std;

/*
 dynamic programming
 frog is iniatilly on stone 1
 frog repete uma ação até chegar na stone n
 se o frog tá currently on sotne i, jump to stone i +1, depois, i + 2, até i + K
 custo: |hi - hj|
 achar o custo mínimo possível antes do frog reach stone n
 */

/*
 recebe numStones (também é o objetivo)
 recebe limite
 faz um for com num stones
 add no vector
 armazena com programação dinâmica
 If we follow the path (10 30 40 50 20)
1 → 2 → 5, the total cost incurred would be
    |10 - 30| + |30 - 20| = 30
 */

int main() {
    int numStones, limite;
    cin >> numStones >> limite;

    vector<int> path(numStones);
    for (int i = 0; i < numStones; ++i) {
        cin >> path[i];
    }

    vector<int> dp(numStones, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < numStones; i++) {
        for (int j = 1; j <= limite; j++) {
            if (i - j >= 0) {
                int cost = abs(path[i] - path[i - j]) + dp[i - j];
                dp[i] = min(dp[i], cost);
            }
        }
    }

    cout << dp[numStones - 1] << endl;

    return 0;
}
