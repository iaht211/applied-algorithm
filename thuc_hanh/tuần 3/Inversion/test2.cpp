#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
const int MOD = 1e9 + 7;
int a[N];
int ta[N];
int n;
int res = 0;

void merge(int b, int m, int e) {
    int i =  b;
    int j = m+1;
    int k = b;
    int cnt = 0;
    while(i <= m && j <= e) {
        if(a[i] <= a[j]) {
            ta[k] = a[i];
            i++;
            k++;
        }
        else {
            cnt += m-i+1;
            cnt %= MOD;
            ta[k] = a[j];
            j++;
            k++;
        }
    }
    
    while(i <= m) {
        ta[k] = a[i];
        k++;
        i++;
    }
    while(j <= e) {
        ta[k] = a[j];
        k++;
        j++;
    }
    for(int m = b; m <= e; m++) a[m] = ta[m];
    res += cnt;
    res %= MOD;
        
}

void mergeSort(int b, int e) {
    if(b == e) return;
    int m = (b + e)/2;
    mergeSort(b, m);
    mergeSort(m+1, e);
    merge(b, m, e);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    mergeSort(1, n);
    cout << res << endl;
    return 0;
}