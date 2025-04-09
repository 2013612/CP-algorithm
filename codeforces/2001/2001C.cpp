#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, dsu[1004];
set<pair<int, int>> s;
vector<pair<int, int>> ans;

int find(int a) {
	if (dsu[a] == a) {
		return a;
	}
	return dsu[a] = find(dsu[a]);
}

void merge(int a, int b) {
	dsu[find(a)] = dsu[find(b)];
}

void search(int a, int b) {
	printf("? %d %d\n", a, b);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	merge(a, b);
	s.insert({a, b});
	if (x == a || x == b) {
		ans.push_back({a, b});
	} else {
		if (!(s.count({a, x}) || s.count({x, a}))) {
			search(a, x);
		}
		
		if (!(s.count({b, x}) || s.count({x, b}))) {
			search(x, b);
		}
	}
}

void solve() {
	scanf("%d", &n);
	s.clear();
	ans.clear();
	for (int i = 1; i <= n; i++) {
		dsu[i] = i;
	}
	
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (find(i) != find(j)) {
				search(i, j);
			}
		}
	}
	
	printf("!");
	for (int i = 0; i < ans.size(); i++) {
		printf(" %d %d", ans[i].first, ans[i].second);
	}
	printf("\n");
	fflush(stdout);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}