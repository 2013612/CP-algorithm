#include<iostream>
#include<bitset>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int n, q;
bitset<100005> bit[100005];

int main() {
	scanf("%d %d", &n, &q);
	
	mint x = 0;
	
	for (int i = 0; i < q; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a = 1 + ((a * (1 + x)).val() % 2);
		b = 1 + ((b * (1 + x)).val() % n);
		c = 1 + ((c * (1 + x)).val() % n);
		
		if (a == 1) {
			bit[b][c] = 1;
			bit[c][b] = 1;
		} else {
			auto temp = bit[b] & bit[c];
			int pos = temp._Find_next(0);
			if (pos > n) {
				pos = 0;
			}
			printf("%d\n", pos);
			x = pos;
		}
	}
	
	return 0;
}