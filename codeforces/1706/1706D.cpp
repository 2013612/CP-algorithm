#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006], k, b[200006][2];

void solve() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	ans = 1e9;
	
	int ma = a[n - 1] / k;
	int mi = ma;
	for (int i = n - 2; i >= 0; i--) {
		printf("# %d %d\n", ma, mi);
		if (ma == 0) {
			printf("0\n");
			return;
		}
		int t1 = min(a[i] / mi, k);
		
		printf("$ %d\n", t1);
		if (t1 == 0) {
			t1++;
		}
		
		if (t1 == 1 && a[i] <= mi) {
			mi = a[i];
			continue;
		}
		
		if (a[i] / t1 < mi) {
			t1--;
		}
		
		if (mi <= a[i] / t1 && a[i] / t1 <= ma) {
			continue;
		}
		
		if (t1 < k) {
			int q1 = a[i] / (t1 + 1);
			int q2 = a[i] / t1;
			if (ma - q1 <= q2 - mi) {
				mi = q1;
			} else {
				ma = q2;
			}
		} else {
			ma = a[i] / t1;
		}
	}
	printf("! %d\n", ma - mi);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}