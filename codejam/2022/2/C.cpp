#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;

int n;
pii child[1004], candy[1004];

bool find(set<int> &a, set<int> &b, vector<pii> &ans) {
	if (ans.size() == n) {
		return true;
	}
	bool can = false;
	for (int i = 0; i < n; i++) {
		if (a.count(i)) {
			continue;
		}
		long long dis = 4e18;
		int id = -1;
		for (int j = 0; j <= n; j++) {
			if (b.count(j)) {
				continue;
			}
			long long dx = child[i].first - candy[j].first;
			long long dy = child[i].second - candy[j].second;
			if (dx * dx + dy * dy <= dis) {
				dis = dx * dx + dy * dy;
				id = j;
			}
		}
		if (id > 0) {
			ans.push_back({i, id});
			a.insert(i);
			b.insert(id);
			if (find(a, b, ans)) {
				can = true;
				break;
			}
			ans.pop_back();
			a.erase(i);
			b.erase(id);
		}
	}
	return can;
}

void solve() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		child[i] = {a, b};
	}
	for (int i = 0; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		candy[i] = {a, b};
	}
	vector<pii> ans;
	set<int> child, candy;
	if (find(child, candy, ans)) {
		printf("POSSIBLE\n");
		for (int i = 0; i < n; i++) {
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	} else {
		printf("IMPOSSIBLE\n");
	}
}


//void solve() {
//	int n;
//	scanf("%d", &n);
//	pii child[1004], candy[1004];
//	for (int i = 0; i < n; i++) {
//		int a, b;
//		scanf("%d %d", &a, &b);
//		child[i] = {a, b};
//	}
//	for (int i = 0; i <= n; i++) {
//		int a, b;
//		scanf("%d %d", &a, &b);
//		candy[i] = {a, b};
//	}
//	pli dis[1004][1004];
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <= n; j++) {
//			long long dx = child[i].first - candy[j].first;
//			long long dy = child[i].second - candy[j].second;
//			dis[i][j] = {dx * dx + dy * dy, -j};
//		}
//		sort(dis[i], dis[i] + n + 1);
//	}
//	pii ord[1004];
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <= n; j++) {
//			if (dis[i][j].second == 0) {
//				ord[i] = {j, i};
//				break;
//			}
//		}
//	}
//	sort(ord, ord + n);
//	for (int i = 0; i < n; i++) {
//		if (ord[i].first <= i) {
//			printf("IMPOSSIBLE\n")
//			return;
//		}
//	}
//	for (int )
//}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}