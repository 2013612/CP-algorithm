#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

long long A1, A2, A3;
int main() {
	scanf("%lld %lld %lld", &A1, &A2, &A3);
	long long diff = 2 * A2 - A1 - A3;
	if (diff >= 0) {
		printf("%lld\n", diff);
	} else if (diff & 1) {
		printf("%lld\n", (-diff + 1) / 2 + 1);
	} else {
		printf("%lld\n", -diff / 2);
	}
	return 0;
}
