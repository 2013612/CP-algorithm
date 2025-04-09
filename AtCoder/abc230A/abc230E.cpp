#include<iostream>
using namespace std;

long long n;
int main() {
	scanf("%lld", &n);
	long long sqrt = 1;
	while (true) {
		if (sqrt * sqrt > n) {
			break;
		}
		sqrt++;
	}
	sqrt--;
	long long ans = 0;
	for (int i = 1; i <= sqrt; i++) {
		ans += n / i;
	}
	printf("%lld\n", 2 * ans - sqrt * sqrt);
	return 0;
}
