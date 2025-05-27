#include<bits/stdc++.h>
using namespace std;

int n, a[300005], l[300005], r[300005], cnt, tra[300005][2];

void solve() {
	scanf("%d", &n);
	
	cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}
	
	int mini = 0;
	int maxi = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			mini++;
			maxi++;
		} else if (a[i] == -1) {
			maxi++;
		}
		
		if (l[i] > maxi || r[i] < mini) {
			printf("-1\n");
			return;
		}
		
		mini = max(mini, l[i]);
		maxi = min(maxi, r[i]);
		
//		printf("!! %d %d\n", mini, maxi);
		
		tra[i][0] = mini;
		tra[i][1] = maxi;
	}
	
	
	
	int last = mini;
	
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] == 1) {
			last--;
		} else if (a[i] == -1) {
			if (last > tra[i - 1][1]) {
				a[i] = 1;
				last--;
			} else {
				a[i] = 0;
			}
		}
	}
	
	a[0] = last;
	
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}