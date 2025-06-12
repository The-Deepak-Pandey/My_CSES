#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int n;
    cin>>n;
    int sum = n*(n+1)/2;
    if(sum%2){
        cout<<"NO"<<endl;
    }
    else{
        int temp = sum/2;
        vector<int> v1, v2;
        cout<<"YES"<<endl;
        while(n){
            if(temp-n>=0){
                v1.push_back(n);
                temp = temp - n;
            }
            else{
                v2.push_back(n);
            }
            n--;
        }
        cout<<v1.size()<<endl;
        for(int it : v1){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<v2.size()<<endl;
        for(int it : v2){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}