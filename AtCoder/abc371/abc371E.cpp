#include<iostream>
using namespace std;

int n, a[200006], b[200006];
long long ans;

int main() {
	scanf("%d", &n);
	
	
	
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		if (a[t] != 0) {
			ans -= 1ll * a[t] * (n - i + 1);
		}
		a[t] = i;
		
		ans += 1ll * i * (n - i + 1);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}