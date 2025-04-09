#include<iostream>
#include<algorithm>
using namespace std;

const int M = 1e8;

int n, a[300006];
long long ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += 1ll * a[i] * (n - 1);
	}
	
	sort(a, a + n);
	
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(a + i + 1, a + n, M - a[i]) - a;
		ans -= 1ll * (n - pos) * M;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}