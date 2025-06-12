#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int n;
    cin>>n;
    int commmm = 0;
    while(n!=0){
        n=n/5;
        commmm+=n;
    }
    cout<<commmm;
}