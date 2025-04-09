#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

int n, a[200006], ans;
vector<int> v[20], dp(1100006, 1e9);
unordered_set<int> us;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		v[a[i] - 1].push_back(i);
	}
	
	dp[0] = -1;
	us.insert(0);
	
	for (int i = 0; i < 20; i++) {
		unordered_set<int> next;
		for (auto x: us) {
			for (int j = 0; j < 20; j++) {
				int k = 1 << j;
				if (x & k) {
					continue;
				}
				
				int node = x | k;
				
				int pos = upper_bound(v[j].begin(), v[j].end(), dp[x]) - v[j].begin();
				if (pos + 1 >= v[j].size()) {
					continue;
				}
				
				next.insert(node);
				
				dp[node] = min(dp[node], v[j][pos + 1]);
				
				ans = max(ans, 2 * (i + 1));
			}
		}
		us = next;
	}
	
	printf("%d\n", ans);
	
	return 0;
}