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


int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
char dirChar[4] = {'D', 'R', 'U', 'L'};

bool inside(int r, int c) {
    return (r >= 0 && r < 7 && c >= 0 && c < 7);
}

int dfs(vector<vector<int>> &vis, int ind, const string &s, int r, int c) {
    if (r == 6 && c == 0) {
        return ind == (int)s.size() ? 1 : 0;
    }

    // prune: reached last step but not at target
    if (ind == (int)s.size()) return 0;

    // prune: if we're in a cul-de-sac (both up/down blocked & left/right open, or vice versa)
    if ((r == 0 || vis[r-1][c]) && (r == 6 || vis[r+1][c]) &&
        c > 0 && !vis[r][c-1] && c < 6 && !vis[r][c+1]) return 0;
    if ((c == 0 || vis[r][c-1]) && (c == 6 || vis[r][c+1]) &&
        r > 0 && !vis[r-1][c] && r < 6 && !vis[r+1][c]) return 0;

    int ans = 0;

    if (s[ind] == '?') {
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (inside(nr, nc) && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                ans += dfs(vis, ind + 1, s, nr, nc);
                vis[nr][nc] = 0;
            }
        }
    } else {
        int i;
        if (s[ind] == 'D') i = 0;
        else if (s[ind] == 'R') i = 1;
        else if (s[ind] == 'U') i = 2;
        else i = 3;
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (inside(nr, nc) && !vis[nr][nc]) {
            vis[nr][nc] = 1;
            ans += dfs(vis, ind + 1, s, nr, nc);
            vis[nr][nc] = 0;
        }
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    vector<vector<int>> vis(7, vector<int>(7, 0));
    vis[0][0] = 1;
    cout << dfs(vis, 0, s, 0, 0) << "\n";
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}