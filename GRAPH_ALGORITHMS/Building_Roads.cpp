#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

int main(){
    int n;
    int m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    
    for(int i = 1; i<= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    vector<pair<int, int>> ans;
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt++;
            if(i > 1) {
                ans.push_back({i-1, i}); // Store the component id
            }
            dfs(i, adj, vis);
        }
    }

    cout << cnt - 1 << endl; // Number of roads to be built
    for(auto it : ans){
        cout << it.first << " " << it.second << endl; // Print the roads to be built
    }
    return 0;
}