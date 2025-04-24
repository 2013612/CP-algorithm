#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;
string s;

void solve() {
	scanf("%d", &n);
	ans = 0;
	cin >> s;
	s = "0" + s + "89";
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (cur != s[i] - '0') {
			cur = 1 - cur;
			ans++;
		}
		ans++;
	}
	
	cur = 0;
	int p1 = 0;
	int p2 = -1;
	
	for (int i = 1; i <= n; i++) {
		if (s[i] != '0') {
			p1 = i;
			break;
		}
	}
	
	int t = 0;
	cur = 1;
	for (int i = p1 + 1; i <= n + 1; i++) {
		if (s[i] == s[p1] || s[i] == '8') {
//			printf("%d\n", i);
			if (p2 > p1) {
				int v = 0;
				if (s[p1 - 1] == s[i - 1]) {
					v++;
				}
				
				if (s[p1] == s[i]) {
					v++;
				}
				t = max(t, v);
				
				p1 = p2;
				p2 = -1;
			}
		} else {
			if (p2 < p1) {
				p2 = i;
			}
		}
	}
	
	printf("%d\n", ans - t);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}