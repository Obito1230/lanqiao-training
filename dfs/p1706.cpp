#include<bits/stdc++.h>
using namespace std;
int n;
int ans[10];
int vis[10];
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            cout<<setw(5)<<ans[i];
        }
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            ans[x]=i;
            dfs(x+1);
            vis[i]=false;
            ans[x]=0;
        }
    }
}
int main (){
    cin>>n;
    dfs(1);
    return 0;
}