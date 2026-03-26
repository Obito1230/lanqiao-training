//前缀和，求余，余数相同时相减可得
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,flag,sum=0;
ll c(ll x){
    if(x>1)
    return x*(x-1)/2;
    else return 0;
}
int main (){
    cin>>n>>k;
    vector<int>arr(k,0);
    arr[0]=1;
    vector<ll>ans(n+1);
    for(int i=1;i<=n;i++){
        ll temp;
        cin>>temp;
        ans[i]=temp+ans[i-1];
        flag=ans[i]%k;
        arr[flag]++;
        ans[i]=flag;
    }
    for(int i=0;i<k;i++){
        ll z=c(arr[i]);
        sum+=z;
    }
    cout<<sum;
    return 0;
}