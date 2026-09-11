#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, edges;

    cout << "Enter vertices: ";
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int source;
    cout << "Enter source: ";
    cin >> source;

    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [distance, node] = pq.top();
        pq.pop();

        if (distance > dist[node])
            continue;

        for (auto [next, weight] : graph[node]) {
            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "\nShortest distances:\n";

    for (int i = 0; i < n; i++) {
        cout << source << " -> " << i
             << " = " << dist[i] << endl;
    }

    return 0;
}
