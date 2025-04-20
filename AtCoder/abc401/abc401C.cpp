#include<bits/stdc++.h>
using namespace std;

const int M = 1e9;

int n, k, ans;
long long a[1000006];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		a[i] = 1;
	}
	long long sum = k;
	
	for (int i = k; i <= n; i++) {
		a[i] = sum;
		sum -= a[i - k];
		sum = (sum + M) % M;
		sum += a[i];
		sum = (sum + M) % M;
	}
	
	printf("%lld\n", a[n]);
	return 0;
}