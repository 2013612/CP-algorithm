#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long N;
int main() {
	scanf("%lld", &N);
	for (long long i = 0; ; i++) {
		if ((1ll << i) > N) {
			printf("%lld\n", i - 1);
			break;
		}
	}
	return 0;
}
