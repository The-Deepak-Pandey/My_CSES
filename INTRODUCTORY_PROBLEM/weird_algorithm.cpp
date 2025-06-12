#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int n;
    cin >> n;
    cout<<n<<" ";
    while (n != 1)
    {
        if (n % 2 == 0) // even
        {
            n = n/2;
        }
        else{
            n= 3*n+1;
        }
        cout<<n<<" ";
    }
    return 0;
}