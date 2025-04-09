#include<bits/stdc++.h>
using namespace std;

int n, k, ans;

void solve() {
	scanf("%d %d", &n, &k);
	
	ans = 1;
	
	n -= k;
	
	if (n > 0) {
		ans += n / (k - 1);
		
		int res = n % (k - 1);
		
		ans += res > 0;
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