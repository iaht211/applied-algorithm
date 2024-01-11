#include<bits/stdc++.h>
#define fi first
#define se second 
#define pb push_back
#define mp make_pair
#define oo 1e9 + 9
#define MAX_N 55
using namespace std;

int ans = oo;
int status[MAX_N];
int dis[MAX_N][MAX_N];
int cur_picked = 0, cur_dropped = 0;
int min_road = oo;
int n, k;
deque<int> drop;

// status = 0 stand 
// = 1 stand for pick up
// = 2 stand for dropped

void Recursion(int cur_index, int last_pos, int cost) {
    if(cost + min_road * (2*n - cur_index) > ans) 
        return;
    if(cur_index == 2*n) {
        ans = min(ans, cost + dis[last_pos][0]);
        return;
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i <= 2*n; i++) {
        for(int j = 0; j <= 2*n; j++) {
            cin >> dis[i][j];
            if(i!=j)
                min_road = min(min_road, dis[i][j]);
        }
    } 


    return 0;
}