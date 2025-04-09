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
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		a[t]++;
		maxi = max(maxi, a[t]);
	}
	
	printf("%d\n", n - maxi);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}