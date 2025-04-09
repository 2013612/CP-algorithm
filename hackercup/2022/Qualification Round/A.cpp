#include<iostream>
using namespace std;

int a[103];

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= 100; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		a[c]++;
	}
	if (n > 2 * k) {
		printf("NO\n");
		return;
	}
	for (int i = 1; i <= 100; i++) {
		if (a[i] > 2) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main() {
	freopen("second_hands_input.txt", "r", stdin);
	freopen("second_hands_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}