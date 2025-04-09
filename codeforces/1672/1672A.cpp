#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[103];

void solve() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += a[i] - 1;
	}
	if (ans % 2 == 0) {
		printf("maomao90\n");
	} else {
		printf("errorgorn\n");
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
