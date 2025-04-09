#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ans = 0;
	int k = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			k = -1;
			continue;
		}
		ans++;
		if (k == -1) {
			if (a[i] <= 2) {
				k = 0;
			} else {
				k = -1;
			}
		} else if (k == 0) {
			if (a[i] <= 2) {
				k = -1;
				ans--;
			} else if (a[i] <= 4) {
				k = 2;
			} else {
				k = -1;
			}
		} else if (k == 2) {
			if (a[i] <= 4) {
				k = 0;
			} else {
				k = -1;
			}
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