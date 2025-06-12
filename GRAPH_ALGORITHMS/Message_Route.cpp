#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1); // To store distance from node 1
    vector<int> parent(n + 1, -1); // To reconstruct the path
    queue<int> q;

    q.push(1);
    dist[1] = 1; // distance in terms of number of computers (1-indexed)

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (dist[it] == -1) { // If not visited
                dist[it] = dist[node] + 1;
                parent[it] = node;
                q.push(it);
            }
        }
    }

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dist[n] << endl;

        vector<int> path;
        int curr = n;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());

        for (auto it : path) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
