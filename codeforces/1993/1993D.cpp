#include<iostream>
using namespace std;

int n, k, a[500005], b[500005][2];

void solve() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int left = 0;
	int right = 1e9 + 1;
	
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		
		for (int i = 0; i < n; i++) {
			if (i % k == 0) {
				b[i][0] = 0;
				b[i][1] = a[i] >= mid;
				if (i >= k) {
					b[i][1] = max(b[i][1], b[i - k][1]);
				}
			} else {
				b[i][0] = max(b[i - 1][0], b[i - 1][1]);
				b[i][1] = b[i - 1][1] + (a[i] >= mid);
				if (i >= k) {
					b[i][0] = max(b[i][0], b[i - k][0]);
					b[i][1] = max(b[i][1], b[i - k][1]);
				}
			}
		}
		
		int size = (n - 1) % k + 1;
		int need = size / 2 + 1;
		
		if (b[n - 1][1] >= need) {
			left = mid;
		} else {
			right = mid;
		}
	}
	
	printf("%d\n", left);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}