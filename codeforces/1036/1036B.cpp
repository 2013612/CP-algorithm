#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long N, x, y, k, ans;

int main(){
	scanf("%lld", &N);
	for (int i = 0 ; i < N; i++) {
		scanf("%lld %lld %lld", &x, &y, &k);
		if (k < max(x, y)) {
			printf("-1\n");
			continue;
		}
		if (x == y) {
			if ((k - x) % 2 == 1) {
				ans = ans - 2;
			}
			ans = ans + k;
		} else {
			if ((x - y) % 2 != 0) {
				ans = k - 1;
			} else {
				ans = k;
				if ((k - max(x, y)) % 2 == 1) {
					ans -= 2;
				}
			}
			
		}
		printf("%lld\n", ans);
		ans = 0;
	}
	return 0;
}
