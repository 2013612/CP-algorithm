#include<bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> a;

void solve() {
	scanf("%d", &n);
	a.resize(n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a.begin(), a.end());
	
	printf("%d\n", a[n - 1] - a[0]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}