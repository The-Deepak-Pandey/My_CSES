#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int total = 0;
vector<int> arr;

int main()
{
    int n;
    cin >> n;
    arr.resize(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    long long ans = 1;

    for(auto it : mp){
        ans = (ans * (it.second + 1)) % MOD;
    }

    cout << (ans - 1 + MOD) % MOD << endl;

    return 0;
}
