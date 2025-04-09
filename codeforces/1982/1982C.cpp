#include<iostream>
using namespace std;

int n, l, r, a[200006], ans;

void solve() {
	scanf("%d %d %d", &n, &l, &r);
	ans = 0;
	int sum = 0;
	int left = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		
		while (sum > r) {
			sum -= a[left];
			left++;
		}
		
		if (sum >= l && sum <= r) {
			ans++;
			sum = 0;
			left = i + 1;
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