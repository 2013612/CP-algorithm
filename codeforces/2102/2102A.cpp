#include<bits/stdc++.h>
using namespace std;

int n, m, p, q;
long long ans;

void solve() {
	scanf("%d %d %d %d", &n, &m, &p, &q);
	
	if (n % p == 0) {
		if (n / p * q != m) {
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