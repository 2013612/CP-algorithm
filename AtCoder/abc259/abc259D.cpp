#include<iostream>
using namespace std;

int n, a[3004], x[3004], y[3004], r[3004];

int find(int k) {
	if (a[k] == k) {
		return k;
	}
	return a[k] = find(a[k]);
}

void merge(int i, int j) {
	a[find(i)] = find(j);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n + 1; i++) {
		a[i] = i;
	}
	
	scanf("%d %d %d %d", &x[n], &y[n], &x[n + 1], &y[n + 1]);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x[i], &y[i], &r[i]);
	}
	
	for (int i = 0; i < n + 1; i++) {
		for (int j = i + 1; j <= n + 1; j++) {
			long long dx = x[i] - x[j];
			long long dy = y[i] - y[j];
			long long dis = dx * dx + dy * dy;
			if (dis <= 1ll * (r[i] + r[j]) * (r[i] + r[j])) {
				if (dis >= 1ll * (r[i] - r[j]) * (r[i] - r[j])) {
					merge(i, j);
				}
			}
		}
	}
	if (find(n) == find(n + 1)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}