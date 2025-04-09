#include<iostream>
using namespace std;

int n, a[300005], b[300005];
long long ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		
		ans += 1ll * i * (n - i + 1);
	}
	
	for (int i = 1; i <= n; i++) {
		int t = b[a[i]];
		
		t += max(0, b[a[i] + 1] - b[a[i]]);
		t += max(0, b[a[i] - 1] - b[a[i]]);
		
		
		ans -= 1ll * (n - i + 1) * t;
		
		b[a[i]] = i;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}