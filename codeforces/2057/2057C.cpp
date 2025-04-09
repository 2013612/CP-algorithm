#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int l, r, a[200006], ans[3];

void solve() {
	scanf("%d %d", &l, &r);
	
	int extra = 0;
	
	{
		int t = 1;
		while (t <= r) {
			t <<= 1;
		}
		
		t >>= 1;
		
		while (t * 2 > r) {
			if ((l & t) && (r & t)) {
				l -= t;
				r -= t;
				extra += t;
			}
			t >>= 1;
		}
		
//		printf("!! %d %d %d %d\n", extra, t, l, r);
		
		t = 1;
		while (t <= r) {
			t <<= 1;
		}
		
		t >>= 1;
		
//		printf("!! %d %d %d %d\n", extra, t, l, r);
		
		if (t - 2 >= l) {
			ans[0] = t - 2;
			ans[1] = t - 1;
			ans[2] = t;
		} else {
			ans[0] = t - 1;
			ans[1] = t;
			ans[2] = t + 1;
		}
	}

	printf("%d %d %d\n", ans[0] + extra, ans[1] + extra, ans[2] + extra);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}