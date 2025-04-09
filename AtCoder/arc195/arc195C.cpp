#include<iostream>
using namespace std;

const int K = 1e7;

void solve() {
	int r, b;
	scanf("%d %d", &r, &b);
	
	if ((r & 1) || (r == 0 && (b & 1))) {
		printf("No\n");
		return;
	}
	
	printf("Yes\n");
	
	int x = 0, y = 0;
	
	if (r == 0) {
		x = K + 2;
		y = K;
		for (int i = 0; i < (b + 1) / 2; i++) {
			x--;
			y--;
			printf("B %d %d\n", x, y);
		}
		
		x--;
		y++;
		
		for (int i = 0; i <= (b - 1) / 2; i++) {
			printf("B %d %d\n", x, y);
			x++;
			y++;
		}
		
		return;
	}
	
	for (int i = 0; i < r / 2; i++) {
		printf("R %d %d\n", K, K + i);
	}
	
	for (int i = r / 2 - 1; i >= 0; i--) {
		printf("R %d %d\n", K + 1, K + i);
	}
	
	x = K + 2;
	y = K;
	if (b > 0 && b % 2 == 0) {
		printf("B %d %d\n", x, y);
	}
	
	for (int i = 0; i < (b + 1) / 2; i++) {
		x--;
		y--;
		printf("B %d %d\n", x, y);
	}
	
	x--;
	y++;
	
	for (int i = 0; i < (b - 1) / 2; i++) {
		printf("B %d %d\n", x, y);
		x++;
		y++;
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