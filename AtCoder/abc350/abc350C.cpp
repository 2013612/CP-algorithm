#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[300006], pos[300006];
vector<pair<int, int>> ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			int k = pos[i];
			ans.push_back({i, k});
			swap(pos[a[i]], pos[i]);
			swap(a[i], a[k]);
		}
	}
	
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}