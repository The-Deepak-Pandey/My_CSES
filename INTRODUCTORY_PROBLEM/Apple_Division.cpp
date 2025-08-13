#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(int idx, ll* arr, ll sum1, ll sum2, ll N)
{
    // If we have reached the end, return the difference
    // between the sums
    if (idx == N) {
        return abs(sum1 - sum2);
    }

    // Choose the current apple in group 1
    ll choose
        = solve(idx + 1, arr, sum1 + arr[idx], sum2, N);

    // Choose the current apple in group 2
    ll notChoose
        = solve(idx + 1, arr, sum1, sum2 + arr[idx], N);

    // Return the minimum of both the choices
    return min(choose, notChoose);
}

int main()
{
    // Sample Input
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the recursive function to find the minimum
    // difference between both the groups
    ll ans = solve(0, arr, 0, 0, n);
    cout << ans;
}