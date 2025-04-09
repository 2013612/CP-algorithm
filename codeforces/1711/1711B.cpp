#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, ans, a[200006];
vector<int> b[200006];

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i].clear();
	}
	
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		b[x].push_back(y);
		b[y].push_back(x);
	}
	
	if (m % 2 == 0) {
		printf("0\n");
		return;
	}
	
	ans = 1e9;
	
	
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}