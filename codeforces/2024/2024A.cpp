#include<iostream>
using namespace std;

int b, ans, a;

void solve() {
	scanf("%d %d", &a, &b);
	
	printf("%d\n", max(0, a - max(b - a, 0)));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}