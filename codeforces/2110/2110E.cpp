#include<iostream>
#include<deque>
#include<unordered_set>
#include<map>
using namespace std;

int n, a[200005][2];
map<pair<int, int>, int> rev;
map<int, unordered_set<int>> edge;

deque<int> f(int st, int ed) {
	deque<int> ans;

	if (edge[st].empty()) {
		return ans;
	}
	
	ans.push_back(st);
	
	int cnt = 0;
	while (ans.size() < n + 1) {
		cnt = 0;
		while (edge[ans.back()].empty() && cnt <= ans.size()) {
			ans.push_front(ans.back());
			ans.pop_back();
			cnt++;
		}
		
		if (cnt > ans.size()) {
			break;
		}
		
		int cur = ans.back();
		int next = *edge[cur].begin();
		ans.push_back(next);
		edge[cur].erase(next);
		edge[next].erase(cur);
	}
	
	for (int i = 0; i < ans.size(); i++) {
		ans.push_front(ans.back());
		ans.pop_back();
		if (ans.front() == st && ans.back() == ed) {
			break;
		}
	}
	
	return ans;
}

void solve() {
	scanf("%d", &n);
	deque<int> ans;
	
	edge.clear();
	rev.clear();
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
		
		a[i][1] += 1e9;
		edge[a[i][0]].insert(a[i][1]);
		edge[a[i][1]].insert(a[i][0]);
		
		rev[{a[i][0], a[i][1]}] = i + 1;
		rev[{a[i][1], a[i][0]}] = i + 1;
	}
	
	int cnt = 0;
	for (auto [x, y]: edge) {
		if ((y.size()) & 1) {
			cnt++;
		}
	}
	
	if (cnt > 2) {
		printf("NO\n");
		return;
	}
	
	
	if (cnt == 2) {
		int u = 0, v = 0;
		for (auto [x, y]: edge) {
			if ((y.size()) & 1) {
				if (u == 0) {
					u = x;
				} else {
					v = x;
				}
			}
		}
		
		ans = f(u, v);
	} else {
		ans = f(a[0][0], a[0][0]);
	}
	
	if (ans.size() != n + 1) {
		printf("NO\n");
		return;
	}
	
	printf("YES\n");
	for (int i = 0; i + 1 < ans.size(); i++) {
		printf("%d ", rev[{ans[i], ans[i + 1]}]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}