//指数型dfs
#include<bits/stdc++.h>
using namespace std;
int n;
char flag;
string arr[25];
int lianjie[25][25];//前面的字符串可以被后面的字符串连上。
int vis[25];
int ans=INT_MIN;
void dfs(string dangqian,int x){
    vis[x]++;
    ans=max((int)dangqian.size(),ans);
    for(int i=1;i<=n;i++){
        if(lianjie[x][i]!=0&&vis[i]<2){
            dfs(dangqian+arr[i].substr(lianjie[x][i]),i);
        }
    }
    vis[x]--;
}
int main (){
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>flag;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<min(arr[i].size(),arr[j].size());k++){
                if(arr[i].substr(arr[i].size()-k)==arr[j].substr(0,k)){
                    lianjie[i][j]=k;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(arr[i][0]==flag){
            dfs(arr[i],i);
        }
    }
    cout<<ans;
    return 0;
}