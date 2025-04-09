#include<iostream>
#include<algorithm>
using namespace std;

int n, w, d;
int main() {
	while (true) {
		scanf("%d %d %d", &n, &w, &d);
		if (n == 0 && w == 0 && d == 0) {
			break;
		}
		int a[203][2];
		a[1][0] = w;
		a[1][1] = d;
		for (int i = 2; i < n + 2; i++) {
			int p, s;
			scanf("%d %d", &p, &s);
			int t0 = a[p][0];
			int t1 = a[p][1];
			for (int j = p + 1; j < i; j++) {
				a[j - 1][0] = a[j][0];
				a[j - 1][1] = a[j][1];
			}
			s = s % (2 * (t0 + t1));
			if (s < t0) {
				a[i - 1][1] = a[i][1] = t1;
				a[i][0] = max(s, t0 - s);
				a[i - 1][0] = min(s, t0 - s);
			} else if (s < t0 + t1) {
				s -= t0;
				a[i - 1][0] = a[i][0] = t0;
				a[i][1] = max(s, t1 - s);
				a[i - 1][1] = min(s, t1 - s);
			} else if (s < 2 * t0 + t1) {
				s -= t0 + t1;
				a[i - 1][1] = a[i][1] = t1;
				a[i][0] = max(s, t0 - s);
				a[i - 1][0] = min(s, t0 - s);
			} else {
				s -= 2 * t0 + t1;
				a[i - 1][0] = a[i][0] = t0;
				a[i][1] = max(s, t1 - s);
				a[i - 1][1] = min(s, t1 - s);
			}
		}
		int ans[203];
		for (int i = 1; i <= n + 1; i++) {
			ans[i] = a[i][0] * a[i][1];
		}
		sort(ans + 1, ans + n + 2);
		printf("%d", ans[1]);
		for (int i = 2; i <= n + 1; i++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
