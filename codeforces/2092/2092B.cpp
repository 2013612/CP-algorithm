#include<bits/stdc++.h>
using namespace std;

int n;

void solve() {
	scanf("%d", &n);
	
	string a, b;
	cin >> a >> b;
	
	int cnt[2] = {0, 0};
	
	for (int i = 0; i < n; i++) {
		cnt[i % 2] += a[i] == '1';
	}
	
	for (int i = 0; i < n; i++) {
		cnt[(1 - (i % 2))] -= b[i] == '0';
	}
	
	if (cnt[0] <= 0 && cnt[1] <= 0) {
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