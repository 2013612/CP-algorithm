#include<bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> a;

void solve() {
	scanf("%d", &n);
	ans = n * 2;
	
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