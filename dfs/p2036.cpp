//p2036
#include <bits/stdc++.h>
using namespace std;
int n;
int s[12];
int b[12];
int vs[12];
int minans=INT_MAX;
bool flag=false;
void dfs(int x){
    if(x>n){
        int sumx=1,sumb=0;
        for(int i=1;i<=n;i++){
            if(vs[i]==1)
            {
                flag=true;
                sumx*=s[i];
                sumb+=b[i];
            }
        }
        if(flag)
        minans=min(minans,abs(sumx-sumb));
        flag=false;
        return ;
    }
        vs[x]=1;
        dfs(x+1);
        vs[x]=0;

        vs[x]=2; 
        dfs(x+1);
        vs[x]=0;
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
