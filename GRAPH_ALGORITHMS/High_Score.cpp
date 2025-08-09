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
    long long n, m;
    cin >> n >> m;
    vector<tuple<long long, long long, long long>> edges;
    edges.reserve(m);

    for(long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({u, v, w});
    }

    vector<ll> dist(n, -INF);
    dist[0] = 0;

    // Bellman–Ford to find max distances
    for (long long i = 0; i < n - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] != -INF && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Detect vertices affected by positive cycles
    vector<bool> inCycle(n, false);
    for (auto &[u, v, w] : edges) {
        if (dist[u] != -INF && dist[u] + w > dist[v]) {
            inCycle[v] = true;
        }
    }

    // Build adjacency lists
    vector<vector<long long>> g(n), rg(n);
    for (auto &[u, v, w] : edges) {
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    // BFS from start
    vector<bool> reachFrom0(n, false);
    queue<long long> q;
    q.push(0);
    reachFrom0[0] = true;
    while (!q.empty()) {
        long long u = q.front(); q.pop();
        for (long long nxt : g[u]) {
            if (!reachFrom0[nxt]) {
                reachFrom0[nxt] = true;
                q.push(nxt);
            }
        }
    }

    // BFS from end in reverse graph
    vector<bool> reachToN1(n, false);
    q.push(n - 1);
    reachToN1[n - 1] = true;
    while (!q.empty()) {
        long long u = q.front(); q.pop();
        for (long long nxt : rg[u]) {
            if (!reachToN1[nxt]) {
                reachToN1[nxt] = true;
                q.push(nxt);
            }
        }
    }

    // If any cycle node is reachable from start and can reach end → infinite score
    for (int i = 0; i < n; i++) {
        if (inCycle[i] && reachFrom0[i] && reachToN1[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << dist[n - 1] << "\n";
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}