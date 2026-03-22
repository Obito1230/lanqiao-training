//p1036
#include<bits/stdc++.h>
using namespace std;
int n, k;
int arr[25];
int ans[25];
int temp;
int cnt = 0;
bool issu(int x) {
    if (x < 2)return false;
    else {
        for (int i = 2;i * i <= x;i++) {
            if (x % i == 0)return false;
        }
        return true;
    }
}
void dfs(int x, int start) {
    if (x == k) {
        temp = 0;
        for (int i = 0;i < k;i++) {
            temp += ans[i];
        }
        if (issu(temp))cnt++;
        return;
    }
    for (int i = start;i < n;i++) {
        ans[x] = arr[i];
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}
int main() {
    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0, 0);
    cout << cnt;
    return 0;
}