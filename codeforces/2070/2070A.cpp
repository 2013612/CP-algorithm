#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200005], ans;

void solve() {
	scanf("%d", &n);
	n++;
	ans = n / 15 * 3;
	
	n %= 15;
	
	ans += min(n, 3);
	
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
