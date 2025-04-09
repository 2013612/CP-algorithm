#include<iostream>
using namespace std;

int n, t0, ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int t, v;
		scanf("%d %d", &t, &v);
		ans -= t - t0;
		t0 = t;
		ans = max(ans, 0);
		ans += v;
	}
	
	printf("%d\n", ans);
	
	return 0;
}