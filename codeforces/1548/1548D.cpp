#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, ans;
long long a[200006];

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int n;  // array size
long long t[400006];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = gcd(t[i<<1], t[i<<1|1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = gcd(res, t[l++]);
    if (r&1) res = gcd(res, t[--r]);
  }
  return res;
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%lld", &a[j]);
		}
		ans = 0;
		n = N - 1;
		for (int j = 0; j < n; j++) {
			t[n + j] = abs(a[j] - a[j + 1]);
		}
		build();
		int left = 0;
		int right = 0;
		while (right < n) {
			if (query(left, right + 1) > 1) {
				ans = max(ans, right - left + 1);
				right++;
			} else {
				left++;
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
