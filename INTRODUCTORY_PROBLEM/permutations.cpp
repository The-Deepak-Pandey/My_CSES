#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int n;
    cin>>n;
    if(n==2 || n==3){
        cout<<"NO SOLUTION";
        return 0;
    }

    if(n%2==0){
        for(int i = 2; i<=n; i+=2){
            cout<<i<<" ";
        }
        for(int i = 1; i<=n-1; i+=2){
            cout<<i<<" ";
        }
    }
    else{
        for(int i = 2; i<=n-1; i+=2){
            cout<<i<<" ";
        }
        for(int i = 1; i<=n; i+=2){
            cout<<i<<" ";
        }
    }
}

