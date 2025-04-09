#include<iostream>
#include<algorithm>
using namespace std;

int n, q, a[100006];

int main() {
	scanf("%d %d", &n, &q);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a, a + n);
	
	for (int i = 0; i < q; i++) {
		int b, k;
		scanf("%d %d", &b, &k);
		
		int left = -1, right = 2e8 + 1;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			int l = lower_bound(a, a + n, b - mid) - a;
			int r = upper_bound(a, a + n, b + mid) - a;
			if (r - l < k) {
				left = mid;
			} else {
				right = mid;
			}
		}
		printf("%d\n", left + 1);
	}
	
	return 0;
}