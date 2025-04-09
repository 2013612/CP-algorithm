#include<iostream>
#include<algorithm>
using namespace std;

int n, k, s[1003];

void solve() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	sort(s, s + n);
	
	if (1ll * s[0] * max(2 * n - 3, 1) > k) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
}

int main() {
	freopen("walk_the_line_input.txt", "r", stdin);
	freopen("walk_the_line_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}