#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, t, ans, a[200006];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (a[n - 1] - a[n - 2] > 1) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
}

int main() {
	scanf("%d", &t);
	while (t-- > 0)  {
		solve();
	}
	return 0;
}
