#include<bits/stdc++.h>
using namespace std;
// #define int long long int

int32_t main(){
   long long int n;
    cin>>n;
    long long power = 1;
    for(int i = 0; i<n; i++){
        power*=2;
        power = power%1000000007;
    }
    cout<<power%1000000007;
}