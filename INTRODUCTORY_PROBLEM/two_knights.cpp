#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int total = (i * i) * (i * i - 1) / 2;
        int attacking = 4 * (i - 1) * (i - 2);
        cout << total - attacking << endl;
    }
}