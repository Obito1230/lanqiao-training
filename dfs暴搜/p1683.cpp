//p1683 
#include<bits/stdc++.h>
using namespace std;
int w,h,rx,ry;
char mp[22][22];
bool vis[22][22]; 
int yidong[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int cnt=1;
void dfs(int x,int y){
    int nx,ny;
    for(int i=0;i<4;i++){
        nx=x+yidong[i][0];
        ny=y+yidong[i][1];
        if(nx>0&&nx<=h&&ny>0&&ny<=w){
            if(mp[nx][ny]!='#'){
                if(!vis[nx][ny]){
                    cnt++;
                    vis[nx][ny]=true;
                	dfs(nx,ny); 
                }
            }
        }
    }
}
int main (){
    cin>>w>>h; 
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='@'){
                rx=i; ry=j;
                vis[rx][ry]=true;
            }
        }
    }
    dfs(rx,ry);
    cout<<cnt;
    return 0;
}
