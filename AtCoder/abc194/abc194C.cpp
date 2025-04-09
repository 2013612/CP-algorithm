#include<iostream>
using namespace std;

long long N, sum1, sum2;
int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		sum1 += temp;
		sum2 += temp * temp;
	}
	printf("%lld\n", N * sum2 - sum1 * sum1);
	return 0;
}
