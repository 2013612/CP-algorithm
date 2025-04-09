#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long x, ans;
int main() {
	scanf("%lld", &x);
	ans = 4e18;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			long long t = i * 10 + j;
			int diff = j - i;
			while (true) {
				if (t >= x) {
					ans = min(ans, t);
					break;
				}
				int k = t % 10 + diff;
				if (k > 9 || k < 0) {
					break;
				}
				t = t * 10 + k;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
