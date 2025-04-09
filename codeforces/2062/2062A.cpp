#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q, a[200006], ans;

void solve() {
	string s;
	cin >> s;
	n = s.size();
	
	ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			ans++;
		}
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}