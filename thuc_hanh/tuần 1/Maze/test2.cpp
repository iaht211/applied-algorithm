#include<bits/stdc++.h>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

int n, m, r, c;
int a[1005][1005];
int visited[1005][1005];
queue<pii> q;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};


int main() {
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    visited[r][c] = 1;
    q.push(mp(r, c));

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for(int i = 1; i <= 4; i++) {
            int new_x = cur_x + dx[i];
            int new_y = cur_y + dy[i];
            if(a[new_y][new_x]) continue;
            if(visited[new_y][new_x]) continue;
            if(new_x == 0 || new_x == (m+1) || new_y == 0 || new_y == (n+1)) {
                cout << visited[cur_y][cur_x] << '\n';
                return 0;
            }
            visited[new_y][new_x] = visited[cur_y][cur_x] + 1;
            q.push(mp(new_y, new_x));

        }
    }
    cout << -1 << '\n';


}