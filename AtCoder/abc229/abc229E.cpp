#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, m, d[200006];
vector<int> edge[200006], ans;
set<int> s;

int find(int x) {
  if (d[x] != x) {
    d[x] = find(d[x]);
  }
  return d[x];
}

void merge(int a, int b) {
	b = find(b);
	if (a != b) {
		d[b] = a;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		d[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
	}
	ans.push_back(0);
	for (int i = n; i >= 2; i--) {
		for (auto x : edge[i]) {
			if (find(x) != i) {
				s.erase(find(x));
			}
			merge(i, x);
		}
		s.insert(i);
		ans.push_back(s.size());
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
