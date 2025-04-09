#include<iostream>
#include<vector>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, q;

int op(int a, int b) {
	return a + b;
}

int e() {
	return 0;
}

int main() {
	scanf("%d", &n);
	
	vector<int> v(500005, 0);
	segtree<int, op, e> seg(v);
	
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		int x = 0;
		int y = l + 1;
		while (x + 1 < y) {
			int mid = (x + y) / 2;
			if (seg.prod(0, mid + 1) + mid < l) {
				x = mid;
			} else {
				y = mid;
			}
		}
		
		int k1 = y;
		
		x = 0;
		y = r + 1;
		
		while (x + 1 < y) {
			int mid = (x + y) / 2;
			if (seg.prod(0, mid + 1) + mid <= r) {
				x = mid;
			} else {
				y = mid;
			}
		}
		
		int k2 = y;
		
		seg.set(k1, seg.get(k1) + 1);
		seg.set(k2, seg.get(k2) - 1);
	}
	
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		int x;
		scanf("%d", &x);
		printf("%d\n", x + seg.prod(0, x + 1));
	}
	
	return 0;
}