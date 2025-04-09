#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], b[200006], ans, k;
bool can[200006][2];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	can[0][0] = can[0][1] = true;
	for (int i = 1; i < n; i++) {
		if (can[i - 1][0]) {
			if (abs(a[i] - a[i - 1]) <= k) {
				can[i][0] = true;
			}
			if (abs(b[i] - a[i - 1]) <= k) {
				can[i][1] = true;
			}
		}
		if (can[i - 1][1]) {
			if (abs(a[i] - b[i - 1]) <= k) {
				can[i][0] = true;
			}
			if (abs(b[i] - b[i - 1]) <= k) {
				can[i][1] = true;
			}
		}
	}
	if (can[n - 1][0] || can[n - 1][1]) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
