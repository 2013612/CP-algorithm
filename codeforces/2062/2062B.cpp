#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q, a[500006], ans;

void solve() {
	scanf("%d", &n);
	
	bool can = true;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		can = can && (a[i] > (2 * max(i, n - i - 1)));
	}

	if (can) {
		printf("YES\n");
	} else {
		printf("NO\n");
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