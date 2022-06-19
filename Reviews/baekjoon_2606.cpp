#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int node, edge;
    cin >> node >> edge;
    vector<vector<int>> graph(node+1);

    int begin, end;
    for(int i = 0; i < edge; i++) {
        cin >> begin >> end;
        graph[begin].push_back(end);
        graph[end].push_back(begin);
    }

    for(int i = 1; i < node+1; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    int answer = 0;
    queue<int> que;
    vector<bool> visited(node+1, false);
    int start = 1;

    que.push(start);
    visited[start] = true;

    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if(!visited[next]) {
                que.push(next);
                visited[next] = true;
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}