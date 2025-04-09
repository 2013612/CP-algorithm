#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (n > 200) {
		if ((a[0] == 0 && a[n - 2] == 0) || (a[1] == 0 && a[n - 1] == 0) || (a[0] == -a[n - 1] && a[1] == 0 && a[n - 2] == 0)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					long long sum = 1ll * a[i] + a[j] + a[k];
					if (!binary_search(a, a + n, sum)) {
						printf("NO\n");
						return;
					}
				}
			}
		}
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