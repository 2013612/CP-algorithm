#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;
long long maxi[2];

void solve() {
	scanf("%d", &n);
	
	ans = 0;
	
	maxi[0] = maxi[1] = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		maxi[a[i] % 2] = max(maxi[a[i] % 2], 1ll * a[i]);
	}
	
	sort(a, a + n);
	
	if (maxi[1] == 0) {
		printf("0\n");
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] & 1) {
			continue;
		}
		
		if (a[i] > maxi[1]) {
			ans++;
			maxi[1] += maxi[0];
		}
		
		ans++;
		maxi[1] += a[i];
	}
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	
	while (t-- > 0) {
		solve();
	}
	
	return 0;	
}