#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    struct Edge {
        int u, v;
        long long w;
    };
    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    const long long INF = 1e18;
    vector<long long> dist(n + 1, 0);  // start with 0 so all nodes get processed
    vector<int> parent(n + 1, -1);
    int x = -1;

    // Bellman-Ford
    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = max(-INF, dist[e.u] + e.w);
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // Rewind n times to ensure we are inside the cycle
        for (int i = 0; i < n; i++) {
            x = parent[x];
        }

        vector<int> cycle;
        int cur = x;
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != x);
        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());

        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
