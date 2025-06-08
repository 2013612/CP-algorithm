#include<bits/stdc++.h>
using namespace std;

int n, m, a[300005];

void solve() {
	scanf("%d %d", &n, &m);
	int x1 = 1, x2 = 2;
	
	for (int i = 3; i <= n; i++) {
		int temp = x1 + x2;
		x1 = x2;
		x2 = temp;
	}
	
	string ans = "";
	
	for (int i = 0; i < m; i++) {
		int w, l, h;
		scanf("%d %d %d", &w, &l, &h);
		
		if (w < l) {
			swap(w, l);
		}
		
		if (w < h) {
			swap(w, h);
		}
		
		if (w >= (x1 + x2) && l >= x2 && h >= x2) {
			ans.push_back('1');
		} else {
			ans.push_back('0');
		}
	}
	
	cout << ans << endl;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}