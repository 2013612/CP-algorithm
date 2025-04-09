#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long N, ans;
int main() {
	scanf("%lld", &N);
	if (N < 1000) {
		ans = 0;
	} else if (N < 1000000) {
		ans = N - 999;
	} else if (N < 1000000000) {
		ans = N * 2 - 999999 - 999;
	} else if (N < 1000000000000) {
		ans = N * 3 - 999999999 - 999999 - 999;
	} else if (N < 1000000000000000) {
		ans = N * 4 - 999999999999 - 999999999 - 999999 - 999;
	} else if (N < 1000000000000000000){
		ans = N * 5 - 999999999999999 - 999999999999 - 999999999 - 999999 - 999;
	}
	printf("%lld\n", ans);
	return 0;
}
