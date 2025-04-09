#include<bits/stdc++.h>
using namespace std;

int n, m;
long long a[300005], b[300005], ans;

int main() {
	scanf("%d %d", &n, &m);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%lld", &b[i]);
	}
	
	sort(a, a + n, greater<long long>());
	sort(b, b + m, greater<long long>());
	
	int cnt = n;
	
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			cnt = i;
			break;
		}
		
		ans += a[i];
	}
	
	for (int j = 0; j < m; j++) {
		if (j >= cnt) {
			if (j >= n) {
				break;
			}
			
			if (a[j] + b[j] >= 0) {
				ans += a[j] + b[j];
			}
			
		} else {
			if (b[j] < 0) {
				break;
			}
			
			ans += b[j];
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}