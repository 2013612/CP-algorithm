#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> a;
int main() {
	scanf("%d", &n);
	a.push_back({-1, 0});
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if ((a.back().first == t && a.back().second % 2 == 0) || (a.back().first == 1 - t && a.back().second % 2 == 1)) {
			a.back().second++;
		} else {
			a.push_back({t, 1});
		}
	}
	a.push_back({-1, 0});
	int ans = 0;
	for (int i = 1; i < a.size() - 1; i++) {
		int l = a[i].second;
		if ((a[i - 1].first == a[i].first && a[i - 1].second % 2 == 1) || (a[i - 1].first != a[i].first && a[i - 1].second % 2 == 0)) {
			l += a[i - 1].second;
		}
		if ((a[i + 1].first == a[i].first && a[i].second % 2 == 1) || (a[i + 1].first != a[i].first && a[i].second % 2 == 0)) {
			l += a[i + 1].second;
		}
		ans = max(ans, l);
	}
	printf("%d\n", ans);
	return 0;
}
