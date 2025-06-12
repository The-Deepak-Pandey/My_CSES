#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> y >> x;
        if (y > x)
        {
            if (y % 2 != 0)
            {
                cout << (y - 1) * (y - 1) + (x - 1) + 1;
            }
            else
            {
                cout << y * y - (x - 1);
            }
        }
        else
        {
            if (x % 2 != 0)
            {
                cout << x * x - (y - 1);
            }
            else
            {
                cout << (x - 1) * (x - 1) + (y - 1) + 1;
            }
        }
        cout<<endl;
    }
}