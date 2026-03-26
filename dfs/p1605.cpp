#include<bits/stdc++.h>
using namespace std;
int mp[8][8];
bool vis[8][8];
int ix[4]={1,-1,0,0};
int iy[4]={0,0,1,-1};
int n,m,t;
int cnt=0;
int sx,sy,fx,fy;
void dfs(int x,int y){
    if(x==fx&&y==fy){
        cnt++;
    }
    if(!vis[x][y]){
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int xa=x+ix[i];
            int ya=y+iy[i];
            if(xa<1||xa>n||ya<1||ya>m)continue;
            if(vis[xa][ya])continue;
            if(mp[xa][ya]==1)continue;
            dfs(xa,ya);
        }
        vis[x][y]=false;
    }
}
int main (){
    memset(mp,0,sizeof(mp));
    memset(vis,false,sizeof(vis));
    cin>>n>>m>>t>>sx>>sy>>fx>>fy;
    while(t--){
        int zx,zy;
        cin>>zx>>zy;
        mp[zx][zy]=1;
    }
    dfs(sx,sy);
    cout<<cnt;
}