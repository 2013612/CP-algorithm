#include<iostream>
using namespace std;

int n, a[200006];
long long pre_sum[200006];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pre_sum[i + 1] = pre_sum[i] + a[i];
	}
	string s;
	cin >> s;
	long long ans = 0;
	int left = 0;
	int right = n - 1;
	while (left < right) {
		if (s[left] != 'L') {
			left++;
		} else if (s[right] != 'R') {
			right--;
		} else {
			ans += pre_sum[right + 1] - pre_sum[left];
			left++;
			right--;
		}
	}
	
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