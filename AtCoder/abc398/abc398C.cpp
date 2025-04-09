#include<bits/stdc++.h>
using namespace std;

int n, ans, a[300005];
map<int, int> m;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m[a[i]]++;
	}
	
	ans = -1;
	int k = -1;
	
	for (auto [x, y]: m) {
		if (y == 1) {
			k = max(k, x);
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] == k) {
			ans = i + 1;
			break;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}