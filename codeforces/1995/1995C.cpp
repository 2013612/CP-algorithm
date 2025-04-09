#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int n, a[200006], b[200006];
long long ans;

void solve() {
	scanf("%lld", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		b[i] = 0;
	}
	
	ans = 0;
	
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			if (a[i] == 1) {
				printf("-1\n");
				return;
			}
		}
		
		long double t1 = b[i - 1] + log2l(log2l(a[i - 1]));
		long double t2 = log2l(log2l(a[i]));
		
		b[i] = max((long double)0, ceil(t1 - t2 - 1e-9));
//		cout << "! " << i << " " << b[i] << " " << t1 - t2 << endl;
//		printf("! %d %d %.17Le\n", i, b[i], t1 - t2);
//		if (t2 < t1) {
//			
//			b[i] = ceil(log(t1 / t2));
//			printf("! %d %d\n", i, b[i]);
//		}
	}
	
	for (int i = 0; i < n; i++) {
		ans += b[i];
	}
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}