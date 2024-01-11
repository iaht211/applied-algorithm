// chuyển số thập phân thành số nhị phân

#include<bits/stdc++.h>
using namespace std;
int a[100];
int n;
void in() {
    for(int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << '\n';
}
void dequy(int k) {
    for(int i = 0; i <= 1; i++) {
        a[k] = i;
        if(k == n) {
            in();
        }
        else dequy(k + 1);
    }
}

int main() {
    cin >> n;
    dequy(1);
}