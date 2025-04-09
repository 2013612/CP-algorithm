#include<iostream>
using namespace std;

int n, q, s[10005];

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
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		s[i] = i;
	}
	for (int i = 0; i < q; i++) {
		int c, x, y;
		scanf("%d %d %d", &c, &x, &y);
		if (c == 0) {
			merge(x, y);
		} else {
			printf("%d\n", same(x, y));
		}
	}
	return 0;
}
