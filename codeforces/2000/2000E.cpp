#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k, w, a[200006];

void solve() {
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d", &w);
	
	for (int i = 0; i < w; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + w, greater<int>());
	long long ans = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int lti = max(i - k + 1, 1);
			int ltj = max(j - k + 1, 1);
			int rbi = min(i, n - k + 1);
			int rbj = min(j, m - k + 1);
			int temp = (rbi - lti + 1) * (rbj - ltj + 1);
//			printf("! %d %d %d %d %d %d %d\n", i, j, lti, ltj, rbi, rbj, temp);
			v.push_back(temp);
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	
	for (int i = 0; i < w; i++) {
		ans += 1ll * a[i] * v[i];
	}
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}