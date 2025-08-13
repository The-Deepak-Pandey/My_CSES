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


bool canPlace(vector<vector<char>>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false; // Check column
    }
    for (int i = 0; i < row; i++) {
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false; // Check left diagonal
        if (col + (row - i) < 8 && board[i][col + (row - i)] == 'Q') return false; // Check right diagonal
    }
    return true;
}


int help(vector<vector<char>>& board, int row, int col) {
    if (row == 8) {
        return 1; // All queens placed successfully
    }
    int count = 0;
    for (int c = 0; c < 8; c++) {
        if (canPlace(board, row, c) && board[row][c] == '.') {
            board[row][c] = 'Q'; // Place queen
            count += help(board, row + 1, c); // Recur to place next queen
            board[row][c] = '.'; // Backtrack
        }
    }
    return count;
}


void solve() {
    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    int result = help(board, 0, 0);
    cout << result << endl;
}

int main() {
    fastio;

    int t=1;
    while (t--) {
        solve();
    }

    return 0;
}