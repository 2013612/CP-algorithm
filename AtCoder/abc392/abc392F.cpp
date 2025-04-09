#include<iostream>
#include<vector>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, p[500005], a[500005];

int f(int a, int b) {
	return a + b;
}

int e() {
	return 0;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	
	vector<int> v(n, 1);
	segtree<int, f, e> seg(v);
	
	for (int i = n - 1; i >= 0; i--) {
		int l = -1;
		int r = n;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			
			if (seg.prod(0, mid + 1) >= p[i]) {
				r = mid;
			} else {
				l = mid;
			}
		}
		a[r] = i + 1;
		seg.set(r, 0);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	
	printf("\n");
	
	return 0;
}