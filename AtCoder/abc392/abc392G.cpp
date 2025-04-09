#include<iostream>
#include<vector>
using namespace std;

int n, a[2000006];
long long ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	
	for (int i = 1; i <= 3; i++) {
		long long cnt = 0;
		for (int j = i; j <= 12; j += i) {
			if (a[j]) {
				cnt++;
			} else {
				printf("%d %d %d\n", i, j, cnt);
				ans += max(cnt - 2, 0ll);
				cnt = 0;
			}
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}