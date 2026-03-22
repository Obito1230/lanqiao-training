//p2036
#include <bits/stdc++.h>
using namespace std;
int n;
int s[12];
int b[12];
int vs[12];
int minans=INT_MAX;
bool flag=false;//只有有调料被选择的时候才进行比较 
void dfs(int x){
    if(x>n){
        int sumx=1,sumb=0;//因为x是求积，所以要初始化为1 
        for(int i=1;i<=n;i++){
            if(vs[i]==1)
            {
                flag=true;//有调料被选择时标记 
                sumx*=s[i];
                sumb+=b[i];
            }
        }
        if(flag)
        minans=min(minans,abs(sumx-sumb));
        flag=false;//回溯标记 
        return ;
    }

        
        
        vs[x]=1;//等于1的时候选 
        dfs(x+1);
        vs[x]=0;

        vs[x]=2;//等于2的时候不选 
        dfs(x+1);
        vs[x]=0;//回溯 
}
int main (){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>b[i];
    }
    dfs(1);
    cout<<minans;
    return 0;
}
