#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, a[300005], ans;

void solve() {
	scanf("%d %d", &n, &k);
	string s;
	cin >> s;
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int l = -1, r = 1e9 + 1;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		
		int cnt = 0;
		bool st = false;
		for (int i = 0; i < n; i++) {
			if (st) {
				if (a[i] > mid && s[i] == 'R') {
					st = false;
				}
			} else {
				if (a[i] > mid && s[i] == 'B') {
					st = true;
					cnt++;
				}
			}
		}
		
		if (cnt <= k) {
			r = mid;
		} else {
			l = mid;
		}
	}
	
	printf("%d\n", r);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}
