#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, m, ans;
set<pair<int, int>> s;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		s.insert({u, v});
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (s.count({i, j}) && s.count({i, k}) && s.count({j, k})) {
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}