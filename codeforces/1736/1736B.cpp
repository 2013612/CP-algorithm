#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t = 1;
int a[200006], b[200006];

int gcd(int c, int d) {
	return d == 0 ? c : gcd(d, c % d);
}

void solve() {
	int n, ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = 0;
	}
	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		b[i] = (a[i - 1] * a[i]) / gcd(a[i - 1], a[i]);
	}
	b[n] = a[n - 1];
	bool can = true;
	for (int i = 0; i < n; i++) {
		can = can && (a[i] == gcd(b[i], b[i + 1]));
	}
	
	if (can) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}