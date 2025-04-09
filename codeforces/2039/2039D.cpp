#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

int m, n, a[200006], ans[200006], di[200006];
unordered_set<int> us[200006];

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[m - i - 1]);
	}
	
	for (int i = 1; i <= n; i++) {
		ans[i] = 1;
	}
	
	ans[1] = 0;
	
	bool has = true;
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + i; j <= n; j += i) {
			if (ans[j] == ans[i]) {
				ans[j]++;
			}
		}
		
		if (ans[i] == m) {
			has = false;
			break;
		}
	}
	
	if (!has) {
		printf("-1\n");
	} else {
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[ans[i]]);
		}
		printf("\n");
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