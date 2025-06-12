#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int n;
    cin >> n;
    int ans = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i >= 1)
        {
            if (arr[i] < arr[i - 1])
            {
                ans+= arr[i-1]-arr[i];
                arr[i]+=arr[i-1]-arr[i];
            }
        }
    }
    cout<<ans<<endl;
}