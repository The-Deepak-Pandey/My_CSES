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


ll help(ll r, ll c, vector<vector<char>> &grid, vector<vector<int>> &dp){

    if(r == grid.size()-1 && c == grid.size()-1){
        if(grid[r][c] == '*') return 0;
        return 1;
    }

    if(dp[r][c] != -1) return dp[r][c];

    ll ways = 0;

    // going right
    ll nr = r;
    ll nc = c+1;
    if(nc < grid.size() && nc >= 0 && grid[nr][nc]=='.'){
        ways += help(nr, nc, grid, dp)%MOD;
    }

    // going down
    nr = r+1;
    nc = c;
    if(nr < grid.size() && nr >= 0 && grid[nr][nc]=='.'){
        ways += help(nr, nc, grid, dp)%MOD;
    }

    return dp[r][c] = ways%MOD;
}


void solve() {
    ll n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char> (n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if(grid[0][0] == '*') cout << 0 << endl;
    else{

    vector<vector<int>> dp(n, vector<int> (n, -1));

    cout << help(0, 0, grid, dp) << endl;}
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}