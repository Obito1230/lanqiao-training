//全排列形dfs;
#include<bits/stdc++.h>
using namespace std;
struct plane{
    int id;
    int starttime;
    int d;
    int l;
};
int T,N;
plane arr[15];
int vis[15];
bool dfs(int x,int time){
    if(x>=N)return true;
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            if(time<=arr[i].starttime+arr[i].d){
                vis[i]=1;
                if(dfs(x+1,max(arr[i].starttime,time)+arr[i].l))//如果一路顺利，最终找到了降落方案，则返回true。若不加return true 那么正确方案会被覆盖，如果不加if，则不会执行回溯步骤，此行非常重要！！！！
                    return true;
                vis[i]=0;
            }
        }
    }
    return false;
}
int main (){
    cin>>T;
    while(T--){
        cin>>N;
        memset(arr,0,sizeof(arr));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=N;i++){
            cin>>arr[i].starttime>>arr[i].d>>arr[i].l;
            arr[i].id=i;
        }
        if(dfs(0,0)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}