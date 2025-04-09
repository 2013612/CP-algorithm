#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans, k;

void solve() {
	scanf("%d %d", &n, &k);
	
	if (k == 0) {
		printf("0\n");
		return;
	}
	
	k -= n;
	
	ans = 1;
	
	for (int i = n - 1; i > 0; i--) {
		if (k > 0) {
			ans++;
			k -= i;
		}
		if (k > 0) {
			ans++;
			k -= i;
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