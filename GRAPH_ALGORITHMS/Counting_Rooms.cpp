#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &mat, vector<vector<int>> &vis, int row, int col, int n, int m){
    vis[row][col] = 1;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    for(int i = 0; i < 4; i++){
        int nrow = row + dr[i];
        int ncol = col + dc[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == '.'){
            dfs(mat, vis, nrow, ncol, n, m);
        }
    }
}

int main(){
    int n;
    int m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char> (m));
    vector<vector<int>> vis(n, vector<int> (m, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> mat[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && mat[i][j] == '.'){
                ans++;
                dfs(mat, vis, i, j, n, m);
            }
        }
    }

    cout << ans << endl;

    return 0;

}