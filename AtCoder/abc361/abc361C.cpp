#include<iostream>
#include<algorithm>
using namespace std;

int n, k, a[200006], ans = 2e9;

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	
	for (int i = 0; i <= k; i++) {
		ans = min(ans, a[i + (n - k - 1)] - a[i]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}