#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &color, vector<int> &vis, int col) {
    vis[node] = 1;
    color[node] = col;

    for (auto it : adj[node]) {
        if (vis[it] == 0) {
            if (!dfs(it, adj, color, vis, !col)) {
                return false; // If the adjacent node cannot be colored properly
            }
        } else if (color[it] == col) {
            return false; // If the adjacent node has the same color
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){ 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1); // -1 means uncolored
    vector<int> vis(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            if(!dfs(i, adj, color, vis, 0)) {
                cout << "IMPOSSIBLE" << endl;
                return 0; // If the graph is not bipartite
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << color[i] + 1 << " "; // Output the color (1 or 2)
    }
}