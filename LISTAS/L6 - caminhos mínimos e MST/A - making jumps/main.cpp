#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> chessboard(10, vector<int>(10, 0));
int result, numCases;

void isItValid(int row, int col, int count) {
    int rowMove[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int colMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for(int i = 0; i < 8; i++) {
        int nextRow = row + rowMove[i], nextCol = col + colMove[i];

        if (nextRow >= 0 and nextRow < numCases and nextCol >= 0 and nextCol < 10 and chessboard[nextRow][nextCol] == 0) {
            chessboard[nextRow][nextCol] = 1;
            isItValid(nextRow, nextCol, count+1);
            chessboard[nextRow][nextCol] = 0;
        }
    }

    if(count > result) {
        result = count;
    }
}

int main() {
    int unreachable, sum, colum;
    int caseNow = 1;

    while (cin >> numCases and numCases != 0) {
        int squares = 0;
        result = 0;

        for(int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                chessboard[i][j] = -1;
            }
        }

        for(int i = 0; i < numCases; i++) {
            cin >> unreachable >> sum;

            if(i == 0) {
                colum = unreachable;
            }

            squares += sum;
            for (int j = 0; j < sum; j++) {
                chessboard[i][unreachable + j] = 0;
            }
        }

        chessboard[0][colum] = 1;
        isItValid(0, colum, 1);

        result = squares - result;

        cout << "Case " << caseNow << ", " << result << " square";
        if (result != 1) {
            cout << "s";
        }
        cout << " can not be reached." << endl;

        caseNow++;
    }

    return 0;
}
