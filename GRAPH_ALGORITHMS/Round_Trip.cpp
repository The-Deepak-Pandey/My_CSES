#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int par, int start, int end, vector<int> &parent, vector<int> &cycle) {
    if(start != -1 && end != -1) return true; // If a cycle has already been found
    vis[node] = 1;
    parent[node] = par; // Store the parent of the current node

    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it, adj, vis, node, start, end, parent, cycle)) return true; // If a cycle is found
        } else if(it != par) {
            start = node; // If we find a visited node that is not the parent, we have a cycle
            end = it; // This is the node that completes the cycle
            // print the cycle
            // cycle.push_back(start);
            int current = node;
            while(current != it) {
                cycle.push_back(current);
                current = parent[current]; // Move to the parent until we reach the start of the cycle
            }
            cycle.push_back(it); // Add the end node to complete the cycle
            cycle.push_back(start); // Add the start node to complete the cycle

            return true; // If we find a visited node that is not the parent, a cycle exists
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);

    vector<int> parent(n + 1, -1); // To store the parent of each node
    vector<int> cycle; // To store the cycle if found
    bool foundCycle = false;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(dfs(i, adj, vis, -1, -1, -1, parent, cycle)) {
                foundCycle = true;
                break; // If a cycle is found, we can stop
            }
        }
    }
    if(!foundCycle) {
        cout << "IMPOSSIBLE" << endl; // If no cycle is found
    } else {
        cout << cycle.size() << endl; // Output the size of the cycle
        for(auto it : cycle) {
            cout << it << " "; // Output the nodes in the cycle
        }
        cout << endl;
    }

}