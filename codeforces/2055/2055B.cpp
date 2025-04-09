#include<iostream>
using namespace std;

int n;
long long a[200006], b[200006];

void solve() {
	scanf("%d", &n);
	
	long long extra = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			extra += b[i] - a[i];
			a[i] += 2 * (b[i] - a[i]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i] + extra) {
			printf("NO\n");
			return;
		}
	}
	
	printf("YES\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}