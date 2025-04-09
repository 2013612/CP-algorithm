#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
pair<pair<int, int>, int> a[200006];
vector<int> ans;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first.second, &a[i].first.first);
		a[i].second = i + 1;
	}
	sort(a, a + n);
	
	int max_pow = a[0].first.second;
	
	ans.push_back(a[0].second);
	
	for (int i = 1; i < n; i++) {
		if (a[i].first.second >= max_pow) {
			ans.push_back(a[i].second);
			max_pow = a[i].first.second;
		}
	}
	
	sort(ans.begin(), ans.end());
	
	printf("%d\n", ans.size());
	for (auto x: ans) {
		printf("%d ", x);
	}
	printf("\n");
	
	return 0;
}