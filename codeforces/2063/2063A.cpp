#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int l, r;

void solve() {
	scanf("%d %d", &l, &r);
	
	if (l == r && l == 1) {
		printf("%d\n", 1);
	} else {
		printf("%d\n", r - l);
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