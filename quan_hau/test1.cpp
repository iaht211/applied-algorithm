#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];
int cnt = 0;

bool check(int k, int i) {
    for(int j = 1; j < k; j++) {
        if(abs(k-j) == abs(i - a[j]) || a[k] == i) {
            return false;
        }
    }
    return true;
}

void Try(int k) {
    for(int i = 1; i <= n; i++) {
        if(check(k, i)) {
            a[k] = i;
            if(k == n) {
                cnt++;
            }
            else 
            Try(k+1);
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    cout << cnt;
}