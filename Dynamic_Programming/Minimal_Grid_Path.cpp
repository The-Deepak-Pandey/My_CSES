#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dx[] = {1, 0};
int dy[] = {0, 1};

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> grid[i][j];

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string result = "";
    vector<pair<int, int>> curr;
    curr.emplace_back(0, 0);
    visited[0][0] = true;
    result += grid[0][0];

    for (int step = 1; step <= 2 * n - 2; ++step) {
        char minChar = 'z';
        vector<pair<int, int>> next;

        for (auto [x, y] : curr) {
            for (int d = 0; d < 2; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < n && ny < n && !visited[nx][ny]) {
                    if (grid[nx][ny] < minChar) {
                        minChar = grid[nx][ny];
                        next.clear();
                        next.emplace_back(nx, ny);
                    } else if (grid[nx][ny] == minChar) {
                        next.emplace_back(nx, ny);
                    }
                    visited[nx][ny] = true;
                }
            }
        }

        result += minChar;
        curr = move(next);
    }

    cout << result << '\n';
}

int main() {
    fastio;
    int t = 1;
    while (t--) solve();
    return 0;
}
