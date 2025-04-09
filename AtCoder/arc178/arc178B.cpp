#include<iostream>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int t, a[3];

void solve() {
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	
	if (a[0] > a[1]) {
		swap(a[0], a[1]);
	}
	
	if (a[2] - a[1] != 0 && a[2] - a[1] != 1) {
		printf("0\n");
		return;
	}
	
	mint ans = 0;
	mint two_inv = 2;
	two_inv = two_inv.inv();
	mint ten = 10;
	mint b0 = ten.pow(a[0] - 1);
	mint b1 = ten.pow(a[0]);
	mint b2 = ten.pow(a[1] - 1);
	mint b3 = ten.pow(a[1]);
	
	if (a[0] < a[1]) {
		if (a[1] == a[2]) {
			ans = (b3 - b2 - b1) * (b1 - b0) + (b1 - b0) * (b1 - b0 + 1) * two_inv;
		} else {
			ans = b0 * (b1 - b0) + (b1 - b0) * (b1 - b0 - 1) * two_inv;
		}
	} else {
		if (a[1] == a[2]) {
			ans = (b1 - b0 - b0 + 1) * (b1 - b0 - b0) * two_inv;
		} else {
			ans = b0 * (b1 - b0) + (b1 - 1) * (b1 - b0 - b0) * two_inv;
		}
	}
	
	printf("%d\n", ans.val());
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
}