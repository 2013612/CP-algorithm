#include<iostream>
using namespace std;

long long ans, a[200006], all;
int n, k;

void find(int cnt, int ind, long long cur, long long x) {
	if (cnt == 0) {
		ans = max(ans, x ^ cur);
		
		return;
	}
	
	if (ind + cnt > n) {
		return;
	}
	
	find(cnt, ind + 1, cur, x);
	find(cnt - 1, ind + 1, cur ^ a[ind], x);
}

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		all = all ^ a[i];
	}
	
	if (k < n - k) {
		find(k, 0, 0, 0);
	} else {
		find(n - k, 0, 0, all);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}