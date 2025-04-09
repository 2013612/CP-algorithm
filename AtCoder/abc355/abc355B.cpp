#include<iostream>
#include<algorithm>
using namespace std;

int n, m, a[203], b[203], c[1004];

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		c[n + i] = b[i];
	}
	sort(a, a + n);
	sort(c, c + n + m);
	
	bool can = false;
	for (int i = 0; i < n - 1; i++) {
		int mi = min(a[i], a[i + 1]);
		int ma = max(a[i], a[i + 1]);
		for (int j = 0; j < n + m - 1; j++) {
			if (mi == c[j] && ma == c[j + 1]) {
				can = true;
			}
		}
	}
	
	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}