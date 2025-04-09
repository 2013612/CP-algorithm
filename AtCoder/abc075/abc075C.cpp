#include<iostream>
using namespace std;

int n, m, ans, a[103], b[103], s[103];

int find(int a) {
	if (s[a] == a) {
		return a;
	} else {
		return s[a] = find(s[a]);
	}
}

void merge(int a, int b) {
	s[find(a)] = find(b);
}

bool same(int a, int b) {
	return find(a) == find(b);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			s[j] = j;
		}
		for (int j = 0; j < m; j++) {
			if (i != j) {
				merge(a[j], b[j]);
			}
		}
		for (int j = 2; j <= n; j++) {
			if (!same(j - 1, j)) {
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
