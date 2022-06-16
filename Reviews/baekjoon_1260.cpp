#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dfs(vector<vector<int>> graph, int start) {
    vector<int> result;

    stack<int> sta;
    vector<bool> visited(graph.size(), false);
    
    sta.push(start);
    visited[sta.top()] = true;
    result.push_back(start);

    while(!sta.empty()) {
        int now = sta.top();
        sta.pop();
        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if(!visited[next]) {
                sta.push(now);
                sta.push(next);
                visited[next] = true;
                result.push_back(next);
                break;
            }
        }
    }

    return result;
}

vector<int> bfs(vector<vector<int>> graph, int start) {
    vector<int> result;

    queue<int> que;
    vector<bool> visited(graph.size(), false);

    que.push(start);
    visited[start] = true;
    result.push_back(start);

    while(!que.empty()) {
        int now = que.front();
        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if(!visited[next]) {
                que.push(next);
                visited[next] = true;
                result.push_back(next);
            }
        }
        que.pop();
    }

    return result;
}

int main() {
    int node_num, edge_num, start;
    cin >> node_num >> edge_num >> start;

    vector<vector<int>> graph(node_num+1);
    int begin = 0;
    int end = 0;
    for(int i = 0; i < edge_num; i++) {
        cin >> begin >> end;
        graph[begin].push_back(end);
        graph[end].push_back(begin);
    }

    for(int i = 1; i < graph.size(); i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> dfs_result = dfs(graph, start);
    vector<int> bfs_result = bfs(graph, start);

    for(int i : dfs_result) {
        cout << i << " ";
    }
    cout << endl;
    for(int i : bfs_result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}