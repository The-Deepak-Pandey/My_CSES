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


int help(int a, int b){ // a > b
    if(a < b) return help(b, a);
    if(a == b) return 0; 

    // axb -> bxb + (a-b)xb
    return 1 + help(a-b, b);
}

void solve(int a, int b) {
    cout << help(a, b) << endl;
}

void solv2e(int a, int b) {

    const int INF = 1e9;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INF));

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j) dp[i][j] = 0;
            else {
                // Horizontal cuts
                for(int k = 1; k < i; k++){
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                }
                // Vertical cuts
                for(int k = 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
                }
            }
        }
    }

    cout << dp[a][b] << endl;
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        int a, b;
        cin >> a >> b;
        solv2e(a, b);
        // solve(a, b);
    }

    return 0;
}