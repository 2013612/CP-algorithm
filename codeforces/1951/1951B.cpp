#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[100006], b[100006], ans, k;

int find_ans() {
	int cnt = 0;
	int maxi = b[0];
	for (int i = 1; i < n; i++) {
		maxi = max(maxi, b[i]);
		if (maxi == a[k]) {
			cnt++;
		} else if (maxi > a[k]) {
			break;
		}
	}
	
	return cnt;
}

void solve() {
	scanf("%d %d", &n, &k);
	k--;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	
	ans = 0;
	ans = max(ans, find_ans());
	
	swap(b[k], b[0]);
	ans = max(ans, find_ans());
	
	swap(b[k], b[0]);
	
	for (int i = 0; i < n; i++) {
		if (a[i] > a[k]) {
			swap(b[k], b[i]);
			ans = max(ans, find_ans());
			break;
		}
	}
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}