#include<iostream>
using namespace std;

int n, a[100006];
int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (int i = 0; i < 100000; i++) {
			a[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			int h1, m1, s1, h2, m2, s2;
			scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
			a[h1 * 60 * 60 + m1 * 60 + s1]++;
			a[h2 * 60 * 60 + m2 * 60 + s2]--;
		}
		int ans = 0;
		for (int i = 1; i <= 100000; i++) {
			a[i] += a[i - 1];
			ans = max(ans, a[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
