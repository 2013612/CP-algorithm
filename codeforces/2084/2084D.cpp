#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> v;

void solve() {
	scanf("%d %d %d", &n, &m, &k);
	v.resize(n);
	
	int cnt = max(n / (m + 1), k);
	
	for (int i = 0; i < n; i++) {
		printf("%d ", i % cnt);
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