#include<bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;

int n, m, r, c;
int visited[1005][1005]; // chứa giá trị đường đi từ điểm chọn đến ô đó
int a[1005][1005]; // chứa ma trận nhập vào
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
queue<pair<int, int>> q;

main() {
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        } 
    }
    visited[r][c] = 1;
    q.push(mp(r, c));
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i = 1; i <= 4; i++){
            int new_x = dx[i] + cur_x;
            int new_y = dy[i] + cur_y;
            if(new_x == 0 || new_x == n+1 || new_y == 0 || new_y == m+1){
                cout << visited[cur_x][cur_y] << "\n";
                return 0;
            }
            if(visited[new_x][new_y])
                continue;
            if(a[new_x][new_y])
                continue;
            
            q.push(mp(new_x, new_y));
            visited[new_x][new_y] = visited[cur_x][cur_y] + 1;
        }
    }


    cout << -1 << "\n";
    return 0;
}

