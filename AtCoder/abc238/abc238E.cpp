#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

int n, q, a[200006];

int find(int x) {
	if (a[x] == x) {
		return x;
	}
	return a[x] = find(a[x]);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i <= n; i++) {
		a[i] = i;
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		a[find(l - 1)] = a[find(r)];
	}
	
	if (find(0) == find(n)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
