#include "bits/stdc++.h"
using namespace std;

// ranking number as follows
// ahmad´s ranking is 0
// for people who worked in the same team with him, the ranking is 1
// for people who worled with people who worked with him, the ranking is 2

// automate the process of calculating the ranking

// recebe numCases
// faz um for com numCases
// recebe o numTeams
// faz um for com o numTeams
// recebe string name1, name2, name3

// output
// for com numCases
// cout listNames.size()
// faz um for com listNames.size()
// cout na ordem do ranking from 0 to the end e depois por ordem lexicográfica

// ahmad will be ofund in one team at least

void bfs(map<string, vector<string>>& graph, map<string, int>& rankings, string start) {
    queue<string> q;
    q.push(start);
    rankings[start] = 0;

    while (!q.empty()) {
        string node = q.front();
        q.pop();

        for (string neighbor : graph[node]) {
            if (rankings[neighbor] == -1) {
                rankings[neighbor] = rankings[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int numCases, numTeams;
    cin >> numCases;

    for (int i = 0; i < numCases; ++i) {
        cin >> numTeams;

        map<string, vector<string>> graph;
        map<string, int> rankings;

        for (int j = 0; j < numTeams; ++j) {
            string name1, name2, name3;
            cin >> name1 >> name2 >> name3;

            graph[name1].push_back(name2);
            graph[name1].push_back(name3);
            graph[name2].push_back(name1);
            graph[name2].push_back(name3);
            graph[name3].push_back(name1);
            graph[name3].push_back(name2);

            rankings[name1] = -1;
            rankings[name2] = -1;
            rankings[name3] = -1;
        }

        bfs(graph, rankings, "Ahmad");

        int count = 0;
        for (const pair<string, int>& student : rankings) {
            count++;
        }

        cout << count << endl;
        vector<pair<string, int>> rankedStudents;
        for (const pair<string, int>& student : rankings) {
            rankedStudents.push_back(make_pair(student.first, student.second));
        }

        sort(rankedStudents.begin(), rankedStudents.end(), [](const pair<string, int>& studentA, const pair<string, int>& studentB) {
            if (studentA.second != studentB.second) {
                return studentA.second < studentB.second;
            }
            return studentA.first < studentB.first;
        });

        for (const pair<string, int>& student : rankedStudents) {
            if (student.second != -1) {
                cout << student.first << " " << student.second << endl;
            }
        }

        for (const pair<string, int>& student : rankedStudents) {
            if (student.second == -1) {
                cout << student.first << " undefined" << endl;
            }
        }
    }

    return 0;
}
