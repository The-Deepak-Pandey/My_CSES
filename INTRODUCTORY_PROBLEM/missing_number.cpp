#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> freq(n, 0);
    for (int i = 1; i <= n-1; i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if(!freq[i]){
            cout<<i<<endl;
            break;
        }
    }
    
    
}