#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000'007;

int rmq[maxn][17];
int n;
int k;
int sum = 0;

int min_length(int l, int r) {
    int length = r - l + 1;
    int result;
    int k = log2(length);
    result = min(rmq[l][k], rmq[r-(1<<k) + 1][k]);
    return result;
}

int main() {
   cin >> n;
   for(int i = 0; i < n; i++) {
        cin >> rmq[i][0];
   }

   for(int j = 1; j <= log2(n); j++) {
        for(int i = 0; i < (n - (1<<j) + 1); i++) {
            rmq[i][j] = min(rmq[i][j-1], rmq[i + (1<<(j-1))][j-1]);
            cout << rmq[i][j] << ' ';
        }
        cout << '\n';
   }
    
    cin >> k;
    for(int v = 0; v < k; v++) {
        int l, r;
        cin >> l >> r;
        sum+=min_length(l, r);
    }

    cout << sum;
   
}