#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int, int> pii;

int n, d, ans;
pii a[200006];
set<pii> b;

bool f(pii a, pii b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + n, f);
	int l = -1;
	int r = -1;
	for (int i = 0; i < n; i++) {
		if (a[i].first > r) {
			l = a[i].second;
			r = a[i].second + d - 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
