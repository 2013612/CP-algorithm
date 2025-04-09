#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, a[200006], ans;

void solve() {
	scanf("%d", &n);
	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		a[i] = i + i - 1;
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}