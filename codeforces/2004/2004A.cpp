#include<iostream>
using namespace std;

int n, a[200006], ans;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j < n; j++) {
			int dis = abs(i - a[j]);
			if (dis == 0) {
				break;
			}
			if (j != 0 && dis > abs(a[j] - a[j - 1])) {
				break;
			}
			if (j != n - 1 && dis > abs(a[j] - a[j + 1])) {
				break;
			}
			
			if (j == n - 1) {
				printf("YES\n");
				return;
			}
		}
	}
	
	printf("NO\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}