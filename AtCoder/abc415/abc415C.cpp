#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;
bool v[500005];
string s;

void dfs(int cur) {
	v[cur] = true;
	for (int i = 0; i < n; i++) {
		int k = (1 << i);
		if (!v[cur | k] && s[cur | k] == '0') {
			dfs(cur | k);
		}
	}
}

void solve() {
	scanf("%d", &n);
	
	cin >> s;
	
	s = "0" + s;
	
	ans = 0;
	
	for (int i = 0; i < (1 << n); i++) {
		v[i] = false;
	}
	
	dfs(0);
	
//	for (int i = 0; i < (1 << n); i++) {
//		printf("%d ", v[i]);
//	}
//	printf("\n");
	
	if (v[(1 << n) - 1]) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}