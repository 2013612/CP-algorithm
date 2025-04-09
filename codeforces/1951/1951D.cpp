#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long n, k;

void solve() {
	scanf("%lld %lld", &n, &k);
	vector<long long> ans;
	long long n1 = n;
	long long k1 = k;
	while (n >= k && k > 0) {
		if (n / (n / k) == k) {
			ans.push_back(n / k);
		} else {
			ans.push_back(n / k + 1);
		}
		k -= n / ans.back();
		n %= ans.back();
	}
	
	if (k == 0) {
		printf("YES\n%d\n", ans.size());
		for (auto x: ans) {
			printf("%lld ", x);
		}
		printf("\n");
	} else {
		if (n1 >= k1 && n1 / (n1 - k1 + 1) + (n1 % (n1 - k1 + 1)) == k1) {
			printf("YES\n2\n");
			printf("%lld 1\n", n1 - k1 + 1);
		} else {
			printf("NO\n");
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}