#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, ans, a[1004];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] = (a[i - 1] + a[i]) % 360;
	}
	sort(a, a + n + 1);
	ans = 360 - a[n];
	for (int i = 1; i <= n; i++) {
		ans = max(ans, a[i] - a[i - 1]);
	}
	printf("%d\n", ans);
	return 0;
}
