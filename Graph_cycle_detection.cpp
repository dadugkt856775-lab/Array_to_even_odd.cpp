#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, edges;

    cout << "Enter vertices: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    bool cycle = false;

    for (int start = 0; start < n; start++) {
        if (visited[start])
            continue;

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int next : graph[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    parent[next] = node;
                    q.push(next);
                }
                else if (parent[node] != next) {
                    cycle = true;
                }
            }
        }
    }

    if (cycle)
        cout << "Cycle exists in the graph.";
    else
        cout << "No cycle exists.";

    return 0;
}
