#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200005], ans;

void solve() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 1; i < n - 1; i++) {
		scanf("%d", &a[i]);
	}
	a[0] = 0;
	a[n - 1] = 0;
	
	int last = -100;
	
	for (int i = 1; i < n - 1; i++) {
		if (a[i] == 1) {
			if (last + 2 == i) {
				printf("NO\n");
				return;
			}
			last = i;
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