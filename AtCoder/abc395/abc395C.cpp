#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[300005], b[1000006], ans = 1e9;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		
		if (b[a[i]] != 0) {
			ans = min(ans, i - b[a[i]] + 1);
		}
		b[a[i]] = i;
	}
	
	if (ans > 1e7) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}