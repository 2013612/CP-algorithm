#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[200006], cur;

void solve() {
	scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		printf("? %d %d\n", 1, i);
		fflush(stdout);
		int r;
		scanf("%d", &r);
		if (r == 1) {
			a[i] = 0;
		} else {
			a[i] = 1;
			cur = i + 1;
			break;
		}
	}
	
	int l = 2;
	
	while (cur < n) {
		printf("? %d %d\n", l, cur);
		fflush(stdout);
		int r;
		scanf("%d", &r);
		
		if (r == 0) {
			a[cur] = l;
			cur++;
		}
		
		l++;
	}
	
	printf("!");
	for (int i = 1; i < n; i++) {
		printf(" %d", a[i]);
	}
	printf("\n");
	fflush(stdout);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}