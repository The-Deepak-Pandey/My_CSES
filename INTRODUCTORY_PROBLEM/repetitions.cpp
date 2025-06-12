#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int n;
    string arr;
    int maxer = 1, counter = 1;
    cin >> arr;
    n = arr.length();
    for (int i = 0; i < n; i++)
    {
        if (i >= 1)
        {
            if (arr[i] == arr[i - 1])
            {
                counter++;
                if (counter > maxer)
                {
                    maxer = counter;
                }
            }
            else
            {
                counter = 1;
            }
        }
    }

    cout << maxer;
}