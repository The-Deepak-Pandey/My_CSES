#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<long long, int> prefix_count;
    prefix_count[0] = 1;

    long long curr_sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        curr_sum += a[i];
        ans += prefix_count[curr_sum - x];
        prefix_count[curr_sum]++;
    }

    cout << ans << '\n';
    return 0;
}
