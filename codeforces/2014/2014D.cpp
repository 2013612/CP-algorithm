#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

typedef pair<int, int> pii;

int n, d, k, ans;
pii a[400006];

pii op(pii a, pii b) {
	return {max(a.first, b.first), min(a.second, b.second)};
}

pii e() {
	return {0, 2e9};
}

void solve() {
	scanf("%d %d %d", &n, &d, &k);
	vector<int> b(n + 1);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		a[i] = {x, y};
		b[x]++;
		b[y + 1]--;
	}
	
	for (int i = 1; i <= n; i++) {
		b[i] += b[i - 1];
	}
	
	vector<pii> c(n);
	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
		c[i] = {b[i], b[i]};
	}
	printf("\n");
	
	segtree<pii, op, e> seg(c);
	
	int cnt1 = e().first;
	int cnt2 = e().second;
	int ans1 = -1;
	int ans2 = -1;
	
	for (int i = 0; i < n - d + 1; i++) {
		pii temp = seg.prod(i, i + d);
		
		if (temp.first > cnt1) {
			ans1 = i + 1;
			cnt1 = temp.first;
		}
		
		if (temp.second < cnt2) {
			ans2 = i + 1;
			cnt2 = temp.second;
		}
		
		printf("! %d %d %d %d\n", ans1, ans2, cnt1, cnt2);
	}
	
	printf("! %d %d\n", ans1, ans2);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}