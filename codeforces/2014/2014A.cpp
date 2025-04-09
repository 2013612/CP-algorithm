#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, a[400006], ans;

void solve() {
	ans = 0;
	int sum = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0 && sum > 0) {
			ans++;
			sum--;
		} else if (a[i] >= k) {
			sum += a[i];
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