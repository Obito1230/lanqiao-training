#include <bits/stdc++.h>
using namespace std;
int n,k;
int cnt=0;
void dfs(int x,int start,int sum){
    if(x==k){
        if(sum==n){
            cnt++;
        }
        return ;
        
    }
    if(start*(k-x)+sum>n)return ;
    for(int i=start;i*(k-x)+sum<=n;i++){
        int flag=i;
        dfs(x+1,flag,sum+i);
        
    }
}
int main (){
    cin>>n>>k;
    dfs(0,1,0);
    cout<<cnt;
    return 0;
}
