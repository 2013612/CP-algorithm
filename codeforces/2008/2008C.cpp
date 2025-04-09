#include<iostream>
using namespace std;

void solve() {
	int l, r;
	scanf("%d %d", &l, &r);
	
	int i = 1;
	while (true) {
		if (i * (i + 1) / 2 >= (r - l + 1)) {
			printf("%d\n", i);
			break;
		}
		i++;
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