#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

const int sqrt = 448;

int n, q;
mint a[2][200006];
vector<mint> sum[2], up[2], sum_mul, cnt;

void update(int t, int l, int r, int x) {
	int start = l / sqrt;
	int end = r / sqrt;
	
	for (int i = start; i <= end; i++) {
		if (i == start || i == end) {
			mint temp = 0;
			sum[0][i] = 0;
			sum[1][i] = 0;
			for (int j = i * sqrt; j < (i + 1) * sqrt && j < n; j++) {
				if (j >= l && j <= r) {
					a[t][j] += x;
				}
				a[0][j] += up[0][i];
				a[1][j] += up[1][i];
				sum[0][i] += a[0][j];
				sum[1][i] += a[1][j];
				temp += a[0][j] * a[1][j];
			}
			sum_mul[i] = temp;
			up[0][i] = 0;
			up[1][i] = 0;
		} else {
			sum_mul[i] += 1ll * x * sum[1 - t][i];
			sum[t][i] += 1ll * x * cnt[i];
			up[t][i] += x;
		}
	}
}

int find(int l, int r) {
	update(0, l, r, 0);
	
	mint ans = 0;
	
	int start = l / sqrt;
	int end = r / sqrt;
	
	for (int i = start; i <= end; i++) {
		if (i == start || i == end) {
			for (int j = i * sqrt; j < (i + 1) * sqrt && j < n; j++) {
				if (j >= l && j <= r) {
					ans += a[0][j] * a[1][j];
				}
			}
		} else {
			ans += sum_mul[i];
		}
	}
	
	return ans.val();
}

int main() {
	scanf("%d %d", &n, &q);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[0][i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[1][i]);
	}
	
	for (int i = 0; i < n; i++) {
		if (i % sqrt == 0) {
			sum[0].push_back(0);
			sum[1].push_back(0);
			up[0].push_back(0);
			up[1].push_back(0);
			sum_mul.push_back(0);
			cnt.push_back(0);
		}
		
		sum[0].back() += a[0][i];
		sum[1].back() += a[1][i];
		sum_mul.back() += a[0][i] * a[1][i];
		cnt.back()++;
	}
	
	for (int i = 0; i < q; i++) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		if (t == 3) {
			printf("%d\n", find(l - 1, r - 1));
		} else {
			int x;
			scanf("%d", &x);
			update(t - 1, l - 1, r - 1, x);
		}
	}
	
	return 0;
}