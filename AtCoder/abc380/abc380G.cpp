#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

fenwick_tree<int> fw(200006);
int n, k, p[200006];
mint ans, fac[200006];

int sum(int m) {
	mint a = m;
	return (fac[a.val()] * a * (a - 1) / 4).val();
}

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	
	mint total = 0;
	
	for (int i = 0; i < n; i++) {
		total += fw.sum(p[i] + 1, n);
		fw.add(p[i], 1);
	}
	
	fw = fenwick_tree<int>(200006);
	
	mint cur = 0;
	
	for (int i = 0; i < k - 1; i++) {
		cur += fw.sum(p[i] + 1, n);
		fw.add(p[i], 1);
	}
	
	for (int i = k - 1; i < n; i++) {
		cur += fw.sum(p[i] + 1, n);
		fw.add(p[i], 1);
		
		ans += (total - cur) * fac[k] + sum(k);
		
		if (p[i - k + 1] > 0) {
			cur -= fw.sum(0, p[i - k + 1]);
		}
		fw.add(p[i - k + 1], -1);
	}
	
	ans /= fac[k] * (n - k + 1);
	
	printf("%d\n", ans.val());
	
	return 0;
}