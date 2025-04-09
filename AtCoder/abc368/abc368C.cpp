#include<iostream>
using namespace std;

int n, a[200006];

long long ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += a[i] / 5 * 3;
		int x = a[i] % 5;
		while (x > 0) {
			ans++;
			if (ans % 3 == 0) {
				x -= 3;
			} else {
				x--;
			}
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}