#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, edges;

    cout << "Enter number of tasks: ";
    cin >> n;

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    cout << "Enter dependencies: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        order.push_back(node);

        for (int next : graph[node]) {
            indegree[next]--;

            if (indegree[next] == 0)
                q.push(next);
        }
    }

    if (order.size() != n) {
        cout << "Cannot schedule: cycle detected.";
    }
    else {
        cout << "Task order: ";

        for (int x : order)
            cout << x << " ";
    }

    return 0;
}
