#include<bits/stdc++.h>
using namespace std;

int n, m, ans[300005], b[300005], c[300005];
vector<int> a[300005];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int x;
			scanf("%d", &x);
			a[i].push_back(x);
		}
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		c[b[i]] = i;
	}
	
	for (int i = 0; i < m; i++) {
		int k = 0;
		for (int j = 0; j < a[i].size(); j++) {
			k = max(k, c[a[i][j]]);
		}
		ans[k]++;
	}
	
	for (int i = 1; i < n; i++) {
		ans[i] += ans[i - 1];
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
	
	return 0;
}