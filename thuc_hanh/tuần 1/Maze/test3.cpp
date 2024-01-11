#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define mp make_pair

const int maxn = 1000;

int n, m, r, c;
int a[maxn][maxn];
int visited[maxn][maxn];
queue<pii> q;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            cin >> a[i][j];
    
    q.push(mp(r, c));
    visited[r][c] = 1;
    while(!q.empty()) {
        int cur_x = q.front().second;
        int cur_y = q.front().first;
        q.pop();
        for(int i = 1; i <= 4; i++) {
            int new_x = cur_x + dx[i];
            int new_y = cur_y + dy[i];
            if(visited[new_y][new_x]) continue;
            if(a[new_y][new_x]) continue;
            if(new_x == m+1 || new_y == n+1 || new_x == 0 || new_y == 0) {
                cout << visited[cur_y][cur_x];
                return 0;
            }
            q.push(mp(new_y, new_x));
            visited[new_y][new_x] = visited[cur_y][cur_x] + 1;
        }
    }
    cout << -1;
}