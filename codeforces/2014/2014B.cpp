#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, a[400006], ans;

void solve() {
	scanf("%d %d", &n, &k);
	
	int cur = n - k + 1;
	
	if (cur & 1) {
		if ((n - cur) % 4 > 1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	} else {
		if ((n - cur) % 4 == 0 || (n - cur) % 4 == 3) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
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