#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long a[1004];
void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		c1 += a[i];
		c2 += a[i] * a[i];
	}
	if (c2 == c1 * c1) {
		printf("0\n");
		return;
	}
	if (c1 == 0 || (c2 - c1 * c1) % 2 == 1) {
		printf("IMPOSSIBLE\n");
		return;
	}
	
	if (k == 1) {
		long long ans = (c2 - c1 * c1) / (2 * c1);
		if (c2 + ans * ans == (c1 + ans) * (c1 + ans)) {
			printf("%lld\n", ans);
		} else {
			printf("IMPOSSIBLE\n");
		}
		return;
	}
	
	vector<long long> ans;
	long long l = (c2 - c1 * c1) / 2;
	for (int i = -1e7; i <= 1e7; i++) {
		if (c1 + i == 0) {
			if (l - c1 * i == 0) {
				ans.push_back(i);
				break;
			}
			continue;
		}
		if ((l - c1 * i) % (c1 + i) == 0) {
			ans.push_back(i);
			ans.push_back((l - c1 * i) / (c1 + i));
			break;
		}
	}
	
	if (ans.size() > 0 && ans.size() <= k) {
		for (int i = 0; i < ans.size(); i++) {
			printf("%lld%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
		}
	} else {
		printf("IMPOSSIBLE\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
