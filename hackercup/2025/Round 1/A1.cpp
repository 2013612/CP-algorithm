#include<iostream>
using namespace std;

int a[1000006];

void solve() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i < n; i++) {
		ans = max(ans, abs(a[i] - a[i - 1]));
	}

	printf("%d\n", ans);
}

int main() {
	freopen("snake_scales_chapter_1_input.txt", "r", stdin);
	freopen("snake_scales_chapter_1_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}