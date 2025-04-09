#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

int n, a[200006], k;
vector<pii> ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		while (!ans.empty() && ans.back().first > a[i]) {
			ans.pop_back();
		}
		
		if (!ans.empty() && ans[0].first == a[i] && a[n + i] < a[i]) {
			ans.clear();
		}
		
		if (ans.size() < abs(k)) {
			k = 0;
		}
		
		if (ans.empty()) {
			ans.push_back({a[i], a[n + i]});
		} else if (ans[0].second > a[i]) {
			ans.push_back({a[i], a[n + i]});
		} else if (ans[0].second == a[i] && k > 0){
			ans.push_back({a[i], a[n + i]});
		}
		
		if (k == 0) {
			int t1 = ans.back().second;
			int t2 = ans[0].second;
			if (t1 < t2) {
				k = -ans.size();
			} else if (t1 > t2) {
				k = ans.size();
			}
		}
	}
	for (auto x:ans) {
		printf("%d ", x.first);
	}
	for (auto x:ans) {
		printf("%d ", x.second);
	}
	printf("\n");
	return 0;
}
