#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,c;

bool check(vector<int> v, int d){
    int cnt = 1;
    int i=0, last = 1;
    while (i < n-1) {
        while (last < n && v[last]-v[i] < d)  last++;
        if (last < n) cnt++;
        if (cnt >= c) return true;  // c  th? l?y d? c ph?n t?
        i = last;
        last++;
    }
    return false;
}
void solve(){
    cin >> n >> c;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int lo = 0;
    int hi = v[n-1] - v[0];
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if(check(v,mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}