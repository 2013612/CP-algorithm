#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006], m;

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	string s;
	for (int i = 0; i < m; i++) {
		s.push_back('B');
	}
	for (int i = 0; i < n; i++) {
		int b1 = min(a[i], m - a[i] - 1);
		int b2 = max(a[i], m - a[i] - 1);
		if (s[b1] != 'A') {
			s[b1] = 'A';
		} else {
			s[b2] = 'A';
		}
	}
	
	cout << s << endl;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}