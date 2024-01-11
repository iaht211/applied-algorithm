#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].second;
        cin >> v[i].first;
    }

    sort(v.begin(), v.end());
    cout << "----\n";
    for(int i = 0; i < n; i++) {
        cout << v[i].first << ' ';
        cout << v[i].second;
        cout << '\n';
        
    }   
    cout << "\n";

    int cnt = 0; 
    int last = 0;
    for(int i = 0; i < n; i++) {
        if(v[i].second > last) {
            last = v[i].first;
            cnt++;
        }
    }
    cout << cnt;
    
}