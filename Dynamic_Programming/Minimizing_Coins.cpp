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


int help(ll ind, ll x, vector<ll> &c, vector<vector<ll>> &memo){
    if(x < 0) return 1e9;
    if(ind == (ll)c.size()){
        return x == 0 ? 0 : 1e9;
    }

    if(memo[ind][x] != -1) return memo[ind][x];

    // pick current coin
    ll pick = 1e9;
    if(c[ind] <= x)
        pick = 1 + help(ind, x - c[ind], c, memo); // unbounded

    // don't pick current coin
    ll noPick = help(ind + 1, x, c, memo);

    return memo[ind][x] = min(pick, noPick);
}

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<ll> prev(x + 1, INF), curr(x + 1, INF);

    // Base case:
    prev[0] = curr[0] = 0;

    for (ll ind = n - 1; ind >= 0; ind--) {
        for (ll t = 0; t <= x; t++) {
            ll pick = INF;
            if (c[ind] <= t) {
                pick = 1 + curr[t - c[ind]]; // Stay on current index → use curr
            }
            ll noPick = prev[t]; // move to next index → use prev
            curr[t] = min(pick, noPick);
        }
        prev = curr; // Move curr to prev for next index
    }

    ll res = prev[x];
    if (res >= INF)
        cout << -1 << endl;
    else
        cout << res << endl;
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}