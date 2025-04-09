#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i <= 100; i++) {
		a[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp]++;
	}
	
	for (int i = n; i >= 0; i--) {
		if (a[i] & 1) {
			printf("YES\n");
			return;
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