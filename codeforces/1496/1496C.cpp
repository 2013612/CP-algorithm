#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int T, N, m[100006], d[100006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		int m1 = 0;
		int d1 = 0;
		for (int j = 0; j < 2 * N; j++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			if (t1 == 0) {
				m[m1] = abs(t2);
				m1++;
			} else {
				d[d1] = abs(t1);
				d1++;
			}
		}
		sort(m, m + N);
		sort(d, d + N);
		double ans = 0;
		for (int j = 0; j < N; j++) {
			double k = 1ll * m[j] * m[j] + 1ll * d[j] * d[j];
			k = sqrt(k);
			ans += k;
		}
		printf("%.15f\n", ans);
	}
	return 0;
}
