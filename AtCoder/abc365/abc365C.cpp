#include<iostream>
using namespace std;

int n, a[200006];
long long m, sum;

int main() {
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	long long left = 0, right = 1e15;
	while (left + 1 < right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += min(mid, 1ll * a[i]);
		}
		
		if (sum <= m) {
			left = mid;
		} else {
			right = mid;
		}
	}
	
	if (left > m) {
		printf("infinite\n");
	} else {
		printf("%lld\n", left);
	}
	return 0;
}