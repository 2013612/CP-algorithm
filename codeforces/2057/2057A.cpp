#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, a[200006], ans;

void solve() {
	scanf("%d %d", &n, &m);

	printf("%d\n", max(n, m) + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}