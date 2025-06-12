#include <bits/stdc++.h>
using namespace std;

bool isValid(int r, int c, int n, int m, vector<vector<char>> &mat, vector<vector<int>> &vis){
    return r >=0 && r < n && c >= 0 && c < m && mat[r][c] != '#' && vis[r][c] == 0;
}

bool bfs(vector<vector<char>> &mat, vector<vector<int>> &vis, int row, int col, int n, int m, vector<char> &st, vector<vector<char>> &dir){
    
    // {row, col}
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    while(!q.empty()){
        auto topNode = q.front();
        q.pop();

        int r = topNode.first;
        int c = topNode.second;

        if(mat[r][c] == 'B'){

            // Backtrack to find the path
            while(1){
                if(r == row && c == col) break; // Reached the starting point

                st.push_back(dir[r][c]); // Store the direction
                if(dir[r][c] == 'L') c++;
                else if(dir[r][c] == 'R') c--;
                else if(dir[r][c] == 'U') r++;
                else if(dir[r][c] == 'D') r--;

                // If we reach the starting point, we can stop
            }

            return true; // Found the exit
        }

        // Left
        if(isValid(r, c - 1, n, m, mat, vis)){
            q.push({r, c - 1});
            vis[r][c - 1] = 1;
            dir[r][c - 1] = 'L';
        }

        // Right
        if(isValid(r, c + 1, n, m, mat, vis)){
            q.push({r, c + 1});
            vis[r][c + 1] = 1;
            dir[r][c + 1] = 'R';
        }

        // Up
        if(isValid(r - 1, c, n, m, mat, vis)){
            q.push({r - 1, c});
            vis[r - 1][c] = 1;
            dir[r - 1][c] = 'U';
        }

        // Down
        if(isValid(r + 1, c, n, m, mat, vis)){
            q.push({r + 1, c});
            vis[r + 1][c] = 1;
            dir[r + 1][c] = 'D';
        }
    }

    return false; // Exit not found

}

int main(){
    int n;
    int m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char> (m));
    vector<vector<int>> vis(n, vector<int> (m, 0));

    int s_row = -1;
    int s_col = -1;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'A'){
                s_row = i;
                s_col = j;
            }
        }
    }

    if(s_row == -1 || s_col == -1){
        cout << "NO" << endl;
        return 0;
    }


    vector<char> ans_st;
    vector<vector<char>> dir(n, vector<char>(m));

    bool bol = bfs(mat, vis, s_row, s_col, n, m, ans_st, dir);

    if(!bol){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << ans_st.size() << endl;

    while(!ans_st.empty()){
        cout << ans_st.back();
        ans_st.pop_back();
    }

    return 0;

}