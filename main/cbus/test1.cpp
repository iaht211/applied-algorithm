#include<bits/stdc++.h>
using namespace std;

const int maxn = 40;
int a[maxn][maxn];
int visited[maxn] = {0};
int n;
int m;
int x[maxn];
int minC = 1e9+7;
int distCur = 0;
int distMin = 1e9+7;
int passengers = 0;

void enter() {
    cin >> n; cin >> m;
    for(int i = 0; i <= 2*n; i++)
        for(int j = 0; j <= 2*n; j++) {
            cin >> a[i][j];
            if(i!=j) 
            minC = min(minC, a[i][j]);
    }
    x[0] = 0;
    visited[0] = 1;
}
bool check(int v, int k) {
    if(passengers == m) {
        if(v <= n) return false;
    }
    if(a[x[k-1]][v] == 0) return false;
    if(v > n) {
        if(!visited[v-n]) return false;
    }
    if(!visited[v]) return true;
    return false; 
}

void solution() {
    int distAll = distCur + a[x[n-1]][0];
    distMin = min(distAll, distMin);
}


void Try(int k) {
    for(int v = 1; v <= 2*n; v++) {
        if(check(v, k)) {
            x[k] = v;
            visited[v] = 1;
            distCur += a[x[k-1]][v];
            if(v > n) passengers--;
            else passengers++;
            if(k == 2*n) solution();
            else {
                if(distCur + minC*(2*n-k+1) < distMin) Try(k+1);
            }
            visited[v] = 0;
            distCur -= a[x[k-1]][v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    enter();
    Try(1);
    cout << distMin;

}