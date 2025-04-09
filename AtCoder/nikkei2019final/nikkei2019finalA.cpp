#include<iostream>
using namespace std;

int n, a[3003];
long long pre[3003];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		long long maxi = 0;
		for (int j = i; j <= n; j++) {
			maxi = max(maxi, pre[j] - pre[j - i]);
		}
		printf("%lld\n", maxi);
	}
	return 0;
}
