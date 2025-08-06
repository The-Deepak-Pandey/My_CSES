#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string target) {
    int n = s.length();
    int m = target.length();

    // dp[i][j] = min operations to convert s[0..i-1] to target[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases
    for (int i = 0; i <= n; ++i) dp[i][0] = i;         // delete all from s
    for (int j = 0; j <= m; ++j) dp[0][j] = j;         // insert all to s

    // Fill dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == target[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // no operation needed
            } else {
                dp[i][j] = 1 + min({
                    dp[i - 1][j],     // delete
                    dp[i][j - 1],     // insert
                    dp[i - 1][j - 1]  // replace
                });
            }
        }
    }

    return dp[n][m];
}

void solve() {
    string s, target;
    cin >> s >> target;

    cout << editDistance(s, target) << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}