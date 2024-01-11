#include<bits/stdc++.h>
using namespace std;

const int maxn = 12;

int n, h;
int a[2*maxn][2*maxn];
int visited[2*maxn];
int x[2*maxn];
int cur_cost = 0;
int best_cost = 1e9+7;
int minC = 1e9+7;
int passagers = 0;

void input() {
    cin >> n >> h;
    for(int i = 0; i <= 2*n; i++) 
        for(int j = 0; j <= 2*n; j++) 
        {
            cin >> a[i][j];
            if(a[i][j]) minC = min(minC, a[i][j]);
        }

    visited[0] = 1;
    x[0] = 0;
}

void solution() {
    int all_cost = cur_cost + a[x[2*n]][0];
    best_cost = min(best_cost, all_cost);
}

bool check(int k, int i) {
    if(passagers == h) {
        if(i <= n) return false;
    }
    if(a[x[k-1]][i] == 0) return false;
    if(i > n && visited[i-n] == 0) return false;
    if(!visited[i]) return true;
    return false;
}
void Try(int k) {
    for(int i = 1; i <= 2*n; i++) {
        if(check(k, i)) {
            x[k] = i;
            visited[i] = 1;
            cur_cost += a[x[k-1]][i];
            if(i <= n) passagers++;
            else passagers--;
            if(k == 2*n) solution();
            else {
                if(cur_cost + minC*(2*n-k+1) < best_cost) Try(k+1);
            }  
            visited[i] = 0;
            cur_cost -= a[x[k-1]][i];
            if(i <= n) passagers--;
            else passagers++;
        }
    }
}


int main() {
    input();
    Try(1);
    cout << best_cost;
}