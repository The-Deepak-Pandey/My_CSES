#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<int> pos(n, 0);
    for (int i = 0; i < n; i++) {
        int xx;
        cin >> xx;
        x[i] = xx - 1;
        pos[x[i]] = i;
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] < pos[i - 1]) ans++;
    }

    for (int q = 0; q < m; q++) {
        int i, j;
        cin >> i >> j;
        i--, j--;

        int curContribution = 0;

        // Handle before swap
        if (x[i] - 1 >= 0 && x[i] - 1 != x[j]) curContribution += (pos[x[i]] < pos[x[i] - 1]);
        if (x[i] + 1 < n && x[i] + 1 != x[j]) curContribution += (pos[x[i] + 1] < pos[x[i]]);
        if (x[j] - 1 >= 0 && x[j] - 1 != x[i]) curContribution += (pos[x[j]] < pos[x[j] - 1]);
        if (x[j] + 1 < n && x[j] + 1 != x[i]) curContribution += (pos[x[j] + 1] < pos[x[j]]);

        if (abs(x[i] - x[j]) == 1) {
            int a = x[i], b = x[j];
            if (a > b) swap(a, b); // now a < b
            if (pos[b] < pos[a]) curContribution++;
        }

        ans -= curContribution;

        swap(x[i], x[j]);
        pos[x[i]] = i;
        pos[x[j]] = j;

        curContribution = 0;

        // Handle after swap
        if (x[i] - 1 >= 0 && x[i] - 1 != x[j]) curContribution += (pos[x[i]] < pos[x[i] - 1]);
        if (x[i] + 1 < n && x[i] + 1 != x[j]) curContribution += (pos[x[i] + 1] < pos[x[i]]);
        if (x[j] - 1 >= 0 && x[j] - 1 != x[i]) curContribution += (pos[x[j]] < pos[x[j] - 1]);
        if (x[j] + 1 < n && x[j] + 1 != x[i]) curContribution += (pos[x[j] + 1] < pos[x[j]]);

        if (abs(x[i] - x[j]) == 1) {
            int a = x[i], b = x[j];
            if (a > b) swap(a, b);
            if (pos[b] < pos[a]) curContribution++;
        }

        ans += curContribution;
        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
    return 0;
}
