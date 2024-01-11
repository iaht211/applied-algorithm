#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[100];
void solution() {
    for(int i = 1; i <= k; i++) {
        cout << a[i];
    }
    cout << '\n';
}

void Try(int v, int last) {
    for(int i = last+1; i <= n; i++) {
        a[v] = i;
        if(v == k) {
            solution();
        }
        else Try(v+1, i);
    }
}
int main() {
    cin >> n >> k;
    Try(1, 0);
}