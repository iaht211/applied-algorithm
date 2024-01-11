#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;

int n;
int a[21][21];
int x[21];
int visited[21];
int sum=0, sum_best;

void enter() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    visited[1] = 1;
    x[1] = 1;
    sum_best = inf;
}

void update_best_solution(int sum) {
    if(sum + a[x[n]][1] < sum_best) {
        sum_best = sum + a[x[n]][1];
    } 
}


void branch_and_bound(int k) {
    if(sum >  sum_best) {
        return;
    }
    for(int v = 2; v <= n; v++) {
        if(!visited[v]) {
            x[k] = v;
            visited[v] = 1;
            sum += a[x[k-1]][v];
            if(k == n) {
                
                update_best_solution(sum);
            }
            else branch_and_bound(k+1);
            visited[v] = 0;
            sum -= a[x[k-1]][v];
        }
    }
}

int main() {
    enter();
    branch_and_bound(2);
    cout << sum_best;
    
}