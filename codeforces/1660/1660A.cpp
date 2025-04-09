#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, t, ans;

void solve() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a == 0) {
		printf("1\n");
	} else {
		printf("%d\n", a + 2 * b + 1);
	}
}

int main() {
	scanf("%d", &t);
	while (t-- > 0)  {
		solve();
	}
	return 0;
}
