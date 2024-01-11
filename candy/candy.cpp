#include<bits/stdc++.h>
using namespace std;
int m, n;
int f=0;
int a[100];
int cnt = 0;
void dequy(int k) {
    if(k == n) {
        a[k] = m - f;
        cnt++;
        return;
    }
    int m0 = m - f - (n - k);
    for(int i = 1; i <= m0; i++) {
        a[k] = i;
        f = f + i;
        dequy(k + 1);
        f -= i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    dequy(1);
    cout << cnt << '\n';
    return 0;
}