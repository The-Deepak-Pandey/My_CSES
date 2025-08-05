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


bool isPossible(ll mid, vector<ll> &x, ll k){
    ll cursum = 0;
    ll numsubarray = 1;

    for(int i = 0; i < x.size(); i++){
        cursum += x[i];
        if(cursum > mid){
            cursum = x[i];
            numsubarray++;
        }
    }

    return numsubarray <= k;
}


void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    ll low = *max_element(x.begin(), x.end());
    ll high = accumulate(x.begin(), x.end(), 0LL);

    ll ans;

    while(low <= high){
        ll mid = low + (high-low)/2;
        if(isPossible(mid, x, k)){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }

    cout << ans << endl;
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}