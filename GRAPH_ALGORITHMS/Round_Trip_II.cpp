#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited, inStack;
vector<int> parent;
int startCycle = -1, endCycle = -1;

bool dfs(int u) {
    visited[u] = true;
    inStack[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v)) return true;
        }
        else if (inStack[v]) {
            // Found a cycle
            startCycle = v;
            endCycle = u;
            return true;
        }
    }

    inStack[u] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    inStack.assign(n + 1, false);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i)) break;
    }

    if (startCycle == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(startCycle);
        for (int v = endCycle; v != startCycle; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(startCycle);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";

        for (int x : cycle) cout << x << " ";
        cout << "\n";
    }
}