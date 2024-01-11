#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000'005;
const int LOG = 17;
int a[MAX_N][LOG];
int n; 
int sum = 0;
int k;

int rmq(int l, int  r) {
	int length = r - l + 1;
	int k = log2(length);
	return min(a[l][k], a[r - (1<<k) + 1][k]);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	// input
	cin >> n; 
	for(int i = 0; i < n; i++) {
		cin >> a[i][0];
	}
	// progessing
	for(int j = 1; j <= log2(n); j++) {
		for(int i = 0; i < (n - (1<<j) + 1); i++) {
			a[i][j] = min(a[i][j-1], a[i+(1<<(j-1))][j-1]);
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	cin >> k;

	for(int i = 0; i < k; i++) {
		int r, l;
		cin >> l >> r;
		sum += rmq(l, r);
	}
	cout << sum <<'\n';
}