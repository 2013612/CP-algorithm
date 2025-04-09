#include<iostream>
using namespace std;

int n, m, a[100006], b[100006], s[100006];
long long ans[100006];

int find(int a) {
	if (s[a] < 0) {
		return a;
	} else {
		return s[a] = find(s[a]);
	}
}

void merge(int a, int b) {
	int a1 = find(a);
	int b1 = find(b);
	if (-s[a1] < -s[b1]) {
		s[b1] += s[a1];
		s[a1] = b1;
	} else {
		s[a1] += s[b1];
		s[b1] = a1;
	}
}

bool same(int a, int b) {
	return find(a) == find(b);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		s[i] = -1;
	}
	ans[m - 1] = 1ll * n * (n - 1) / 2;
	for (int i = m - 1; i >= 1; i--) {
		ans[i - 1] = ans[i];
		if (!same(a[i], b[i])) {
			ans[i - 1] -= 1ll * s[find(a[i])] * s[find(b[i])];
			merge(a[i], b[i]);
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}
