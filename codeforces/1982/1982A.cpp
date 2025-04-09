#include<iostream>
using namespace std;

void solve() {
	int x1, y1, x2, y2;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	if ((x1 >= y1 && x2 <= y2) || (x1 <= y1 && x2 >= y2)) {
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