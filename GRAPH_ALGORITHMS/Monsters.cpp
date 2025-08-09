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
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    const int INF_INT = 1e9;

    // Collect monsters and A's start
    queue<pair<int,int>> mq;
    vector<vector<int>> distM(n, vector<int>(m, INF_INT));
    int sr = -1, sc = -1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 'M') {
                mq.push({r, c});
                distM[r][c] = 0;
            } else if (grid[r][c] == 'A') {
                sr = r; sc = c;
            }
        }
    }

    auto inside = [&](int r, int c){ return r >= 0 && r < n && c >= 0 && c < m; };
    auto isBoundary = [&](int r, int c){ return r == 0 || r == n-1 || c == 0 || c == m-1; };

    // Multi-source BFS for monsters to compute earliest arrival times
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    while (!mq.empty()) {
        pair<int,int> cur = mq.front(); mq.pop();
        int r = cur.first, c = cur.second;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (inside(nr, nc) && grid[nr][nc] != '#' && distM[nr][nc] == INF_INT) {
                distM[nr][nc] = distM[r][c] + 1;
                mq.push({nr, nc});
            }
        }
    }

    // BFS for A while respecting monster times: A can move to (nr,nc) at time t+1 only if t+1 < distM[nr][nc]
    vector<vector<int>> distA(n, vector<int>(m, INF_INT));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<char>> moveCh(n, vector<char>(m, '?'));

    queue<pair<int,int>> aq;
    aq.push({sr, sc});
    distA[sr][sc] = 0;

    // If A starts on boundary and is safe now
    if (isBoundary(sr, sc) && 0 < distM[sr][sc]) {
        cout << "YES\n0\n\n";
        return;
    }

    const char dirCh[4] = {'U','D','L','R'};
    pair<int,int> exitCell = {-1, -1};
    while (!aq.empty()) {
        pair<int,int> cur = aq.front(); aq.pop();
        int r = cur.first, c = cur.second;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (!inside(nr, nc) || grid[nr][nc] == '#') continue;
            int nt = distA[r][c] + 1;
            // A must arrive strictly before any monster; if no monster reaches, distM is INF and condition holds
            if (nt < distM[nr][nc] && distA[nr][nc] == INF_INT) {
                distA[nr][nc] = nt;
                parent[nr][nc] = {r, c};
                moveCh[nr][nc] = dirCh[k];
                aq.push({nr, nc});
                if (isBoundary(nr, nc)) { exitCell = {nr, nc}; break; }
            }
        }
        if (exitCell.first != -1) break;
    }

    if (exitCell.first == -1) {
        cout << "NO\n";
        return;
    }

    // Reconstruct path
    vector<char> path;
    for (auto cur = exitCell; cur != make_pair(sr, sc); cur = parent[cur.first][cur.second]) {
        path.push_back(moveCh[cur.first][cur.second]);
    }
    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << "\n";
    for (char ch : path) cout << ch;
    cout << "\n";
}

int main() {
    fastio;

    // CSES Monsters expects a single test case
    solve();
    return 0;
}