#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006], b[200006], c[200006];

void solve() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[i + 1] = 0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		c[i + 1] = 0;
	}
	
	int j = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		while (j >= 0 && j < n - 1 && b[j] == b[j + 1]) {
			c[b[j]]++;
			j--;
		}
		if (j < 0 || a[i] != b[j]) {
			if (c[a[i]] > 0) {
				c[a[i]]--;
			} else {
				printf("NO\n");
				return;
			}
		} else {
			j--;
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
