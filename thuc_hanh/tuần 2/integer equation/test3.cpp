#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000'005;
int a[MAX_N], x[MAX_N], n, M;
int cnt = 0;
int q = 0;

void Try(int k) {
    if((k == n) && (M % a[k] == 0)) {
        //x[k] = M - q;
        // for(int i = 1; i <= n; i++) {
        //     cout << x[i] << ' ';
        // }   
        // cout << '\n';
        cnt ++;
        return;
    }
    int m0 = (M - q - (n - k))/a[k];
    for(int i = 1; i <= m0; i++) {
        q += (a[k] * i);
        x[k] = i;
        Try(k+1);
        q -= (a[k] * i);
       // x[k] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> M;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Try(1);
    cout << cnt << '\n';
}