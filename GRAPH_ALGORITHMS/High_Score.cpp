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
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> adj(n);
    for(int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u = u - 1; // Convert to 0-based index
        v = v - 1; // Convert to 0-based index
        adj[i] = make_tuple(u, v, w);
    }

    // write max bellman-ford algorithm here
    vector<ll> dist(n, -INF);
    dist[0] = 0; // Assuming the starting node is 0
    for (int i = 0; i < n - 1; i++) {
        for (const auto& [u, v, w] : adj) {
            if (dist[u] != -INF && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for positive cycles
    bool hasCycle = false;
    vector<bool> inCycle(n, false);
    for (const auto& [u, v, w] : adj) {
        if (dist[u] != -INF && dist[u] + w > dist[v]) {
            hasCycle = true;
            inCycle[v] = true;
        }
    }

    // Build graph for reachability checks
    vector<vector<int>> g(n), rg(n);
    for (const auto& [u, v, w] : adj) {
        g[u].pb(v);
        rg[v].pb(u);
    }

    // BFS from 0
    vector<bool> reachFrom0(n, false);
    queue<int> q;
    q.push(0);
    reachFrom0[0] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!reachFrom0[v]) {
                reachFrom0[v] = true;
                q.push(v);
            }
        }
    }

    // BFS from n-1 in reverse graph
    vector<bool> reachToN1(n, false);
    q.push(n-1);
    reachToN1[n-1] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : rg[u]) {
            if (!reachToN1[v]) {
                reachToN1[v] = true;
                q.push(v);
            }
        }
    }

    bool cycleAffectsPath = false;
    for (int i = 0; i < n; i++) {
        if (inCycle[i] && reachFrom0[i] && reachToN1[i]) {
            cycleAffectsPath = true;
            break;
        }
    }

    if (cycleAffectsPath) cout << -1 << '\n';
    else cout << dist[n-1] << '\n';



}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}