#include<bits/stdc++.h>
using namespace std;

int n, m, a[300005];
long long ans;
map<int, vector<int>> um;

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a, a + m);
	
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d %d ", a[i], a[m - i - 1]);
		}
		printf("\n");
		for (int j = 0; j < 3; j++) {
			printf("%d %d ", a[m - i - 1], a[i]);
		}
		printf("\n");
	}
	
	if (n & 1) {
		for (int i = 0; i < 3; i++) {
			printf("%d %d ", a[n / 2], a[m - n / 2 - 1]);
		}
		printf("\n");
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