#include<iostream>
#include<algorithm>
using namespace std;

int n, m, a[200006], b[200006];

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	
	sort(a, a + n);
	sort(b, b + m);
	
	long long ans = 0;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] >= b[j]) {
			ans += a[i];
			j++;
		}
		i++;
	}
	
	if (j == m) {
		printf("%lld\n", ans);
	} else {
		printf("-1\n");
	}
	
	return 0;
}