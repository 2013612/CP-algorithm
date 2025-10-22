#include<iostream>
using namespace std;

int a[1000006];

void solve() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int ans = 0;
	for (int i = 0; i < 2 * n - 1; i++) {
		printf("%d ", 1);
	}

	printf("%d\n", b);
}

int main() {
	freopen("final_product_chapter_1_input.txt", "r", stdin);
	freopen("final_product_chapter_1_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}