#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int n, p[200006];
vector<int> q[200006];
unordered_map<int, unordered_map<int, int>> mem;

int solve(int a, int b) {
	if (a >= n || b >= n) {
		return 0;
	}
	if (mem[a].count(b)) {
		return mem[a][b];
	}
	int ind = lower_bound(q[p[a]].begin(), q[p[a]].end(), b) - q[p[a]].begin();
	int ans = solve(a + 1, b);
	if (ind < q[p[a]].size()) {
		ans = max(ans, 1 + solve(a + 1, q[p[a]][ind] + 1));
	}
	mem[a][b] = ans;
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		for (int j = 1; j * j <= t; j++) {
			if (t % j == 0) {
				q[j].push_back(i);
				if (j != t / j) {
					q[t / j].push_back(i);
				}
			}
		}
	}
	printf("%d\n", solve(0, 0));
	return 0;
}
