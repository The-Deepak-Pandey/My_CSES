#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<ll>> dist(n + 1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[1].push_back(0);
    pq.push({0, 1});

    while (!pq.empty()) {
        auto top = pq.top();
        ll d = top.first;
        int u = top.second;
        pq.pop();

        if (d > dist[u].back()) continue; // skip if it's not among best distances anymore

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            ll nd = d + w;
            if ((int)dist[v].size() < k) {
                dist[v].push_back(nd);
                sort(dist[v].begin(), dist[v].end());
                pq.push({nd, v});
            }
            else if (nd < dist[v].back()) {
                dist[v].back() = nd;
                sort(dist[v].begin(), dist[v].end());
                pq.push({nd, v});
            }
        }
    }

    for (ll x : dist[n]) cout << x << " ";
    cout << "\n";
}
