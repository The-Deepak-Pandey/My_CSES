#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(ll N, ll X, vector<ll> price, vector<ll> pages)
{
    vector<ll> dp(X + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int C = X; C > 0; C--) {
            if (price[i] > C)
                continue;
            dp[C] = max(dp[C], pages[i] + dp[C - price[i]]);
        }
    }
    return dp[X];
}
int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> price(N), pages(N);
    for (int i = 0; i < N; i++)
        cin >> price[i];
    for (int i = 0; i < N; i++)
        cin >> pages[i];
    cout << solve(N, X, price, pages) << endl;
}
