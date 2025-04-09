#include<iostream>
#include<algorithm>
using namespace std;

int t, n, s[100006];

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		int ans = 0;
		int cur = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &s[j]);
		}
		sort(s, s + n);
		for (int j = 0; j < n; j++) {
			cur = min(cur + 1, s[j]);
			ans = max(ans, cur);
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
