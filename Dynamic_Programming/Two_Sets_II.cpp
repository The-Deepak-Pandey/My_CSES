#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int)(x).size())
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

// Common Functions
ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool is_prime(ll n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0) return false; } return true; }
vector<ll> sieve(ll n) { vector<ll> primes; vector<bool> is_prime(n + 1, true); for (ll p = 2; p <= n; p++) { if (is_prime[p]) { primes.pb(p); for (ll i = p * p; i <= n; i += p) { is_prime[i] = false; } } } return primes; }


vector<vector<int>> dp;

int help(int ind, int n, int target) {
    if (target == 0) return 1;
    if (ind > n || target < 0) return 0;
    if (dp[ind][target] != -1) return dp[ind][target];

    int include = help(ind + 1, n, target - ind);
    int exclude = help(ind + 1, n, target);

    dp[ind][target] = (include + exclude) % MOD;
    return dp[ind][target];
}

void solve() {
    int n;
    cin >> n;
    int target = n * (n + 1) / 2;
    if (target % 2 != 0) {
        cout << 0 << endl;
        return;
    }
    target /= 2;
    dp.assign(n + 2, vector<int>(target + 1, -1));
    int result = help(1, n, target);
    // Each partition is counted twice, so divide by 2
    cout << (result * 1LL * ((MOD + 1) / 2) % MOD) << endl;
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}