#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;

void solve() {
	string s;
	cin >> s;
	
	ans = 0;
	n = s.size();
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '(') {
			ans++;
		} else {
			ans--;
		}
		
		if (ans == 0) {
			printf("YES\n");
			return;
		}
	}
	
	printf("NO\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}