#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k, ans, a[200006];

void solve() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
	}
	
	long long cnt1 = 0;
	long long cnt2 = 0;
	bool odd1 = false;
	bool odd2 = false;
	for (int i = 0; i < k; i++) {
		if (a[i] / n >= 2) {
			cnt1 += a[i] / n;
			if ((a[i] / n) > 2) {
				odd1 = true;
			}
		}
		
		if (a[i] / m >= 2) {
			cnt2 += a[i] / m;
			if ((a[i] / m) > 2) {
				odd2 = true;
			}
		}
	}
	
	if (cnt1 >= m) {
		if (m % 2 == 0 || (m % 2 == 1 && odd1)) {
			printf("Yes\n");
			return;
		}
	} 
	if (cnt2 >= n) {
		if (n % 2 == 0 || (n % 2 == 1 && odd2)) {
			printf("Yes\n");
			return;
		}
	} 
	
	printf("No\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}