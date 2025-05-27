#include<iostream>
using namespace std;

int n, k;
long long a[103], p = 1;
__int128 ans = 1;

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < k; i++) {
		p *= 10;
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		ans *= a[i];
		
		if (ans >= p) {
			ans = 1;
		}
	}
	
	printf("%lld\n", (long long) ans);
	
	return 0;
}