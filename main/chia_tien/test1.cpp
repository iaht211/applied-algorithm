#include<bits/stdc++.h>
using namespace std;

const int maxn = 21;
int n, S, mark[maxn], mark_best[maxn], sum, cnt, cnt_best, maxmoney[maxn];
int t[maxn];

void create_data() {
    cnt_best = n + 1;
    maxmoney[n-1] = t[n-1];
    for(int i = n-2; i >= 0; i--) {
        maxmoney[i] = max(maxmoney[i+1], t[i]);
    }
}

void update_best_solution() {
    if(sum == S && cnt < cnt_best) {
        cnt_best = cnt;
        for(int i = 0; i < n; i++) {
            mark_best[i] = mark[i];
        }
    }
}

void branch_and_bound(int i) {
    if(cnt + (S-sum)/maxmoney[i] >= cnt_best) {
        return;
    }
    for(int j = 0; j <= 1; j++) {
        sum += t[i] * j;
        mark[i] = j;
        cnt += j;
        if(i == n-1) 
            update_best_solution();
        else   
            branch_and_bound(i + 1);
        sum -= t[i] * j;
        cnt -= j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> S;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    create_data();
    branch_and_bound(0);
    cout << cnt_best << '\n';
    return 0;
}