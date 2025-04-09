#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				t ^= a[j];
			}
		}
		if (a[i] == t) {
			printf("%d\n", a[i]);
			return;
		}
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