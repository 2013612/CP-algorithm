#include<iostream>
using namespace std;

int n, a, b;

void solve() {
	scanf("%d %d %d", &n, &a, &b);
	
	if ((a - b) & 1) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}