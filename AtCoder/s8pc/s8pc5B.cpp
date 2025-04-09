#include<iostream>
using namespace std;

int n, m, x[203], y[203];
double r[203];

bool valid(int a, int b) {
	int dx = x[a] - x[b];
	int dy = y[a] - y[b];
	return dx * dx + dy * dy >= (r[a] + r[b]) * (r[a] + r[b]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n + m; i++) {
		scanf("%d %d", &x[i], &y[i]);
		if (i < n) {
			scanf("%lf", &r[i]);
		}
	}
	double l = 0;
	double ri = 200;
	while (abs(ri - l) > 1e-7) {
		double mid = (l + ri) / 2;
		for (int i = n; i < n + m; i++) {
			r[i] = mid;
		}
		bool can = true;
		for (int i = 0; i < n + m; i++) {
			for (int j = i + 1; j < n + m; j++) {
				can = can && valid(i, j);
			}
		}
		if (can) {
			l = mid;
		} else {
			ri = mid - 1e-8;
		}
	}
	if (m == 0) {
		l = 1e9;
		for (int i = 0; i < n; i++) {
			l = min(l, r[i]);
		}
	}
	printf("%.9f\n", l);
	return 0;
}
