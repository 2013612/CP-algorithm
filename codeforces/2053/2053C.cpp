#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, a[200006];
long long ans;

void f(int end, long long cnt, long long extra) {
	if (end < k) {
		return;
	}
	
	long long m = (end + 1) / 2;
//	printf("%d %d %d %lld\n", end, cnt, extra, ans);
	if (end % 2) {
		ans += m * cnt + extra * (cnt / 2);
		f(m - 1, cnt * 2, extra + m);
	} else {
		f(m, cnt * 2, extra + m);
	}
}

void solve() {
	scanf("%d %d", &n, &k);
	ans = 0;
	
	f(n, 1, 0);
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}