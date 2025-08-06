#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) cin >> x[i];

    vector<ll> prev(m + 2, 0), curr(m + 2, 0);

    // Initialize for index 0
    if (x[0] != 0) {
        prev[x[0]] = 1;
    } else {
        for (ll val = 1; val <= m; ++val)
            prev[val] = 1;
    }

    // DP Iteration
    for (ll i = 1; i < n; ++i) {
        fill(curr.begin(), curr.end(), 0);

        for (ll val = 1; val <= m; ++val) {
            if (x[i] != 0 && val != x[i]) continue;

            ll ways = prev[val];
            if (val > 1) ways = (ways + prev[val - 1]) % MOD;
            if (val < m) ways = (ways + prev[val + 1]) % MOD;

            curr[val] = ways;
        }

        swap(prev, curr);
    }

    ll result = 0;
    for (ll val = 1; val <= m; ++val)
        result = (result + prev[val]) % MOD;

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
