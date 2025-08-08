#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // dp[i][j] = maximum score player can get from a[i..j]
    vector<vector<long long>> dp(n, vector<long long>(n));

    for (int i = 0; i < n; ++i)
        dp[i][i] = a[i];

    for (int l = n - 1; l >= 0; --l) {
        for (int r = l + 1; r < n; ++r) {
            dp[l][r] = max(
                a[l] - dp[l + 1][r],
                a[r] - dp[l][r - 1]
            );
        }
    }

    long long total = 0;
    for (int i = 0; i < n; ++i) total += a[i];

    // Final score for first player
    cout << (total + dp[0][n - 1]) / 2 << endl;

    return 0;
}
