#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long N, a, b, k, ans;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		ans = 0;
		scanf("%d %d %d", &a, &b, &k);
		ans += k/2*a;
		ans -= k/2*b;
		if (k % 2 == 1) {
			ans += a;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
