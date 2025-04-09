#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, a[100006], ans;

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n / 2; i++) {
		printf("%d %d ", n - i + 1, i);
	}
	if (n % 2) {
		printf("%d", n / 2 + 1);
	}
	
	printf("\n");
}

int main() {
	scanf("%d", &t);
	
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}