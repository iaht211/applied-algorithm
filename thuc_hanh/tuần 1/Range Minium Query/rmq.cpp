#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1000'005;
const int LOG = 17;
int a[MAX_N][LOG];
int n;
int query(int L, int R) {
    int length = R - L + 1;
    int k = log2(length);
    return min(a[L][k], a[R - (1<<(k)) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // input 
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i][0];
    }
    // processing 
    for(int j = 1; j <= log2(n); j++) {
        for(int i = 0; i + (1<<(j)) - 1 < n; i++) {
            a[i][j] = min(a[i][j-1], a[i + (1<<(j-1))][j-1]);
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    // out put
    int q, sum = 0;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        sum += query(L, R);
    }
    cout << sum << '\n';
    
    return 0;
}