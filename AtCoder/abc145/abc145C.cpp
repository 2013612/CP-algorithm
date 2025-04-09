#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N, x[10], y[10], per[10];
long double ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x[i], &y[i]);
		per[i] = i;
	}
	do {
		for (int i = 0; i < N - 1; i++) {
			long double dx = x[per[i]] - x[per[i + 1]];
			long double dy = y[per[i]] - y[per[i + 1]];
			ans += sqrt(dx * dx + dy * dy);
		}
		per[9]++;
	} while (next_permutation(per, per + N));
	printf("%.9Lf\n", ans / per[9]);
	return 0;
}
