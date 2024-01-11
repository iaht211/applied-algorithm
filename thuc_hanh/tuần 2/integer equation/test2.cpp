#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int n, M, a[10005], X[1005];
int m0;
void dequy(int k) {
    if(M!=0 && k == n && M % a[k] == 0) {
        cnt++;
        return;
    }
    for(int i = 1; i <= M/a[k]; i++) {
        X[k] = i;
        M -= X[k]*a[k];
        dequy(k+1);
        M += X[k]*a[k];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> M;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dequy(1);
    cout << cnt << '\n';
    return 0;
}