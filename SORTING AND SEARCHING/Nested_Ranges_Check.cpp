#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> ranges(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ranges[i] = make_tuple(x, y, i);
    }

    // Sort by start ascending, end descending
    sort(ranges.begin(), ranges.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    vector<int> contains(n), contained(n);
    int max_end = 0;
    for (int i = 0; i < n; ++i) {
        int y = get<1>(ranges[i]);
        int idx = get<2>(ranges[i]);
        if (y <= max_end) contained[idx] = 1;
        max_end = max(max_end, y);
    }

    int min_end = 1e9 + 1;
    for (int i = n - 1; i >= 0; --i) {
        int y = get<1>(ranges[i]);
        int idx = get<2>(ranges[i]);
        if (y >= min_end) contains[idx] = 1;
        min_end = min(min_end, y);
    }

    for (int i = 0; i < n; ++i) cout << contains[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i) cout << contained[i] << " ";
    cout << "\n";

    return 0;
}
