#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t = 1;
int a[200006], b[200006];

void solve() {
	int n, ans1 = 0, ans2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			ans1++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			ans2++;
		}
		if (b[i] == 0) {
			ans2--;
		}
	}
	
	printf("%d\n", min(ans1, abs(ans2) + 1));
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}