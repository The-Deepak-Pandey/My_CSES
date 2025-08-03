#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, k;
    cin >> n >> k;

    ordered_set<int> people;
    for (int i = 1; i <= n; ++i) people.insert(i);

    int idx = 0;
    while (!people.empty()) {
        idx = (idx + k) % people.size(); // kth to remove
        auto it = people.find_by_order(idx);
        cout << *it << " ";
        people.erase(it);
    }
}

int main() {
    fastio;
    int t = 1;
    while (t--) solve();
    return 0;
}
