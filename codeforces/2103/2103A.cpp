#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;
set<int> s;

void solve() {
	scanf("%d", &n);
	ans = 0;
	s.clear();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}
	
	printf("%d\n", s.size());
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}