#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n, L1, L2;
int a[N], F[N];
void showq(deque<int> gq) {
    deque<int> g = gq;
    while(!g.empty()) {
        cout << g.front() << " ";
        g.pop_front();
    }
    cout << '\n';
}

int main() {
    cin >> n >> L1 >> L2;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    deque<int> dq;

    for(int i = 1; i <= n; i++) {
        while(!dq.empty() && dq.front() < i-L2) dq.pop_front();
        int j = i - L1;
        if(j >= 1) {
            while(!dq.empty() && F[dq.back()] < F[j]) dq.pop_back();
            dq.push_back(j);
        }
        F[i] = a[i] + (dq.empty() ? 0 : F[dq.front()]);
        ans = max(ans, F[i]);
    }
    cout << ans << '\n';
}