#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;
void solve() {
	scanf("%d", &n);
	
	if (n == 1) {
		printf("1\n");
	} else if (n & 1) {
		for (int i = 1; i <= (n + 1) / 2; i++) {
			a[2 * (i - 1)] = i;
		}
		for (int i = 0; i < n / 2; i++) {
			a[2 * i + 1] = n - i;
		}
		
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	} else {
		printf("-1\n");
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