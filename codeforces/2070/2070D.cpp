#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 998244353;

int n, a[300005], c[300005];
vector<int> v[300005], d[300005];
long long ans;

void cal_d(int cur, int dis) {
	d[dis].push_back(cur);
	c[cur] = dis;
	for (auto x: v[cur]) {
		cal_d(x, dis + 1);
	}
}

int dfs(int cur) {
	long long t = 0;
	
	long long m = d[c[cur]].size() - 1;
	
	if (cur == 0) {
		m = 1;
	}
	
	for (auto x: v[cur]) {
		t += m * dfs(x);
		t %= M;
	}
	
	return (t + 1) % M;
}

void solve() {
	scanf("%d", &n);
	ans = 0;
	
	for (int i = 0; i <= n; i++) {
		c[i] = -1;
		v[i].clear();
		d[i].clear();
	}
	
	for (int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		v[a[i]].push_back(i);
	}
	
	cal_d(0, 0);
	
	printf("%d\n", dfs(0));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}
