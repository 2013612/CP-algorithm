#include<bits/stdc++.h>
using namespace std;

int n, x;
long long ans;

void solve() {
	scanf("%d %d", &n, &x);
	ans = x;
	int cnt = 0;
	
	{
		int t = x;
		while (t > 0) {
			if (t & 1) {
				cnt++;
			}
			t /= 2;
		}
	}
	
	if (n >= cnt) {
		int noValue = n - cnt;
		int nonOne = cnt - (x & 1);
		
		if (nonOne == 0) {
			if (noValue & 1) {
				ans += noValue + 3;
			} else {
				ans += noValue;
			}
		} else {
			if (noValue & 1) {
				ans += noValue + 1;
			} else {
				ans += noValue;
			}
		}
	}
	
	if (x == 0 && n == 1) {
		ans = -1;
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