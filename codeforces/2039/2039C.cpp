#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int x, ans;
long long m;

void solve() {
	scanf("%d %lld", &x, &m);
	long long k = 1;
	while (k <= x) {
		k *= 2;
	}
	
	ans = 0;
	
	for (int i = 1; i <= min(m, k); i++) {
		int a = x ^ i;
//		printf("%d %d\n", i, a);
		if (a != 0 && (x % a == 0 || i % a == 0)) {
			ans++;
		}
	}
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}