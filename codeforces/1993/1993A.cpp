#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[4], ans;

void solve() {
	scanf("%d", &n);
	
	ans = 0;
	a[0] = a[1] = a[2] = a[3] = 0;
	
	string s;
	cin >> s;
	
	for (int i = 0; i < 4 * n; i++) {
		if (s[i] == '?') {
			continue;
		}
		
		a[s[i] - 'A']++;
	}
	
	for (int i = 0; i < 4; i++) {
		ans += min(a[i], n);
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