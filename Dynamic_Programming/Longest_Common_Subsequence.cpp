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


int help(vector<ll> &a, vector<ll> &b, int ia, int ib){
    if(ia < 0 || ib < 0) return 0;

    if(a[ia] == b[ib]){
        return 1 + help(a, b, ia-1, ib-1);
    }

    return max(help(a, b, ia, ib-1), help(a, b, ia-1, ib));
}


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<vector<ll>> dp(n+1, vector<ll> (m+1, 0));

    for(int ia = 1; ia <= n; ia++){
        for(int ib = 1; ib <= m; ib++){
            if(a[ia-1] == b[ib-1]){
                dp[ia][ib] = 1 + dp[ia-1][ib-1];
            } else{
                dp[ia][ib] = max(dp[ia][ib-1], dp[ia-1][ib]);
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<ll> ans;
    ll i = n;
    ll j = m;
    while(1){
        if(dp[i][j] == 0) break;
        if(dp[i][j] == dp[i-1][j]){
            i = i-1;
        } else if(dp[i][j] == dp[i][j-1]){
            j = j-1;
        } else{
            i = i-1;
            j = j-1;
            ans.push_back(a[i]);
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}