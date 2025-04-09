#include<iostream>
using namespace std;

bool temp(int a, int b) {
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (2 * i - a + (2 * j - b) * 2 == 0) {
				return true;
			}
		}
	}
	
	return false;
}

void solve() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	if (temp(a, b)) {
		printf("YES\n");
	} else {
		printf("NO\n");
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