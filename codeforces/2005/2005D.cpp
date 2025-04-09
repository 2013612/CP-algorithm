#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[200006], ans;

void solve() {
	int n;
	scanf("%d", &n);
	
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
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