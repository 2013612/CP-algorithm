#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	
	printf("%d\n", a[n / 2]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}