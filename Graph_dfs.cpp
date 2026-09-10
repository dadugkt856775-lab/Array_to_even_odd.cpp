#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges:\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);

    cout << "DFS Traversal: ";

    while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (visited[current])
            continue;

        visited[current] = true;
        cout << current << " ";

        for (auto it = graph[current].rbegin();
             it != graph[current].rend(); ++it) {

            if (!visited[*it])
                st.push(*it);
        }
    }

    return 0;
}
