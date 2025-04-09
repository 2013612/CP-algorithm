#include<bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> v;

void solve() {
	scanf("%d", &n);
	
	if (n % 2 == 0) {
		printf("-1\n");
		return;
	}
	
	printf("%d ", n);
	for (int i = 1; i <= n - 1; i++) {
		printf("%d ", i);
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