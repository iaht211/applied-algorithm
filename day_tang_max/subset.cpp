// tìm kiếm dãy tăng lớn nhất
// sử dụng thuật toán: chia để trị 

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int n;

int MaxLeftSeq(int i, int j) {
    int maxL = a[j], sum = 0;
    for(int k = j; k >= i; k--) {
        sum += a[k];
        maxL = max(maxL, sum);
    }
    return maxL;
}

int MaxRightSeq(int i, int j) {
    int maxR = a[j], sum = 0;
    for(int k = i; k <= j; k++) {
        sum += a[k];
        maxR = max(maxR, sum);
    }
    return maxR;
}

int MaxSubSeq(int i, int j) {
    if(i == j) return a[i];
    int mid = (i + j)/2;
    int wL = MaxSubSeq(i, mid);
    int wR = MaxSubSeq(mid + 1, j);
    int wML = MaxLeftSeq(i, mid);
    int wMR = MaxRightSeq(mid + 1, j);
    int wM = wMR + wML;
    return max(max(wL, wR), wM);
}

int main() {
    freopen("data.inp", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cout << MaxSubSeq(1, n) << endl;
    return 0;
}