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

    vector<vector<pair<int, int>>> adj(n), radj(n);
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    auto dijkstra = [&](int src, const vector<vector<pair<int, int>>>& g) {
        const ll INF = 1e18;
        vector<ll> dist(n, INF);
        dist[src] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : g[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };

    // shortest distances from 0 and to n-1
    vector<ll> dist = dijkstra(0, adj);
    vector<ll> rdist = dijkstra(n - 1, radj);

    ll ans = 1e18;
    for (auto [u, v, w] : edges) {
        if (dist[u] == 1e18 || rdist[v] == 1e18) continue; // unreachable
        ll new_score = dist[u] + w / 2 + rdist[v]; // halve this edge
        ans = min(ans, new_score);
    }

    cout << ans << "\n";
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}