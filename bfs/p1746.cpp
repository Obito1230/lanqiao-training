//地图bfs模板
#include<bits/stdc++.h>
using namespace std;
int n;
struct zuobiao{
	int x; int y;
};
char mp[1005][1005];
int cnt[1005][1005];
zuobiao f1, f2;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void bfs(zuobiao x){
	queue<zuobiao>q;
	q.push(x);
	while (!q.empty()){
		zuobiao temp = q.front();
		q.pop();
		for (int i = 0; i<4; i++){
			int a = temp.x + dx[i];
			int b = temp.y + dy[i];
			if (a<1 || a>n || b<1 || b>n)continue;
			if (mp[a][b] == '1')continue;
			if (cnt[a][b] != -1)continue;
			cnt[a][b] = cnt[temp.x][temp.y] + 1;
			q.push({ a, b });
			if (a == f2.x&&b == f2.y)return;
		}
	}
	return;
}
int main(){
	cin >> n;
	memset(cnt, -1, sizeof(cnt));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> mp[i][j];
		}
	}
	cin >> f1.x >> f1.y >> f2.x >> f2.y;
	cnt[f1.x][f1.y] = 0;
	bfs(f1);
	cout << cnt[f2.x][f2.y];
	return 0;
}