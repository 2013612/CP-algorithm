#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, t, ans, a[];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n");
}

int main() {
	scanf("%d", &t);
	while (t-- > 0)  {
		solve();
	}
	return 0;
}
