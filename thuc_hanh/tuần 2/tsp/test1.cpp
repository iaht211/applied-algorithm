#include<bits/stdc++.h>
using namespace std;

const int maxn = 21;

int n;
int a[maxn][maxn];
int visited[maxn];
int x[maxn];
int best_cost=1e9+7;
int cur_cost;
int minC = 1e9+7;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j])  minC = min(minC, a[i][j]);  
        }
    
    visited[1] = 1;
    x[1] = 1;
            
}
bool check(int k, int v) {
    if(a[k][v] == 0) return false;
    if(visited[v]) return false;
    return true;
}

void solution() {
    int all_cost = cur_cost + a[x[n]][1];
    best_cost = min(all_cost, best_cost);
}

void Try(int k) {
    for(int v = 2; v <= n; v++) {
        if(check(k, v)) {
            x[k] = v;
            visited[v] = 1;
            cur_cost += a[x[k-1]][v];
            if(k == n) {
                solution();
            }
            else {
                if(cur_cost + (n-k+1)*minC < best_cost) Try(k+1);
            }
            visited[v] = 0;
            cur_cost -= a[x[k-1]][v];
        }
    }
}


int main() {
    input();
    Try(2);
    cout << best_cost;
}