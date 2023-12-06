#include <bits/stdc++.h>
using namespace std;

/*
 recebe numRows, width, numTimes
 faz um for com numRows
 x - treasure
 @ - entrance/exit
 # - walls
 . - safe walking
 s - spikes

 cannot walk into walls
 success - can make it in and out alive
 impossible - no way you can make out alive
 */

int numRows, width, numSpike;
vector<string> maze;
vector<vector<int>> in;
vector<vector<int>> out;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int success = 0;

void backtrack(int x, int y, int count, int direct) {
    if (count > numSpike) return;

    if (direct == 1) in[x][y] = 1;
    else out[x][y] = 1;

    if (maze[x][y] == 'x' and direct == 1) {
        backtrack(x, y, count, 2);
        return;
    }

    if (maze[x][y] == '@' and direct == 2) {
        success = 1;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int tempx = x + dx[i];
        int tempy = y + dy[i];

        if (tempx >= 0 and tempy >= 0 and tempx < numRows and tempy < width) {
            if (direct == 1 and in[tempx][tempy] == 0) {
                if (maze[tempx][tempy] != '#') {
                    if (maze[tempx][tempy] == 's') backtrack(tempx, tempy, count + 1, direct);
                    else backtrack(tempx, tempy, count, direct);
                }
                if (success)
                    return;
            }
            else if (direct == 2 and out[tempx][tempy] == 0) {
                if (maze[tempx][tempy] != '#') {
                    if (maze[tempx][tempy] == 's') backtrack(tempx, tempy, count + 1, direct);
                    else backtrack(tempx, tempy, count, direct);
                }
                if (success)
                    return;
            }
        }
    }

    if (direct == 1)
        in[x][y] = 0;
    else
        out[x][y] = 0;
}

int main() {
    int startX, startY;
    cin >> numRows >> width >> numSpike;

    maze.resize(numRows);
    in.assign(numRows, vector<int>(width, 0));
    out.assign(numRows, vector<int>(width, 0));

    for (int i = 0; i < numRows; i++) {
        cin >> maze[i];
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == '@') {
                startX = i;
                startY = j;
            }
        }
    }

    success = 0;
    backtrack(startX, startY, 0, 1);

    if (success)
        cout << "SUCCESS" << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
