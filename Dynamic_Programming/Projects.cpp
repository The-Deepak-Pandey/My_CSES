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



void solve() {
    ll n; 
    if (!(cin >> n)) return; 

    struct Project { ll a, b, p; };
    vector<Project> v(n);
    for (ll i = 0; i < n; ++i) cin >> v[i].a >> v[i].b >> v[i].p;

    // Sort by ending day
    sort(v.begin(), v.end(), [](const Project& x, const Project& y){
        if (x.b != y.b) return x.b < y.b;
        return x.a < y.a;
    });

    // Ends array for binary search
    vector<ll> ends(n);
    for (ll i = 0; i < n; ++i) ends[i] = v[i].b;

    // dp[i] = max money using first i projects (1-indexed dp)
    vector<ll> dp(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        const auto& cur = v[i - 1];
        // Find the last project that finishes strictly before cur.a
        ll idx = upper_bound(ends.begin(), ends.end(), cur.a - 1) - ends.begin();
        // Option 1: skip current
        dp[i] = max(dp[i - 1], dp[idx] + cur.p);
    }

    cout << dp[n] << '\n';
}

int main() {
    fastio;

    solve();

    return 0;
}