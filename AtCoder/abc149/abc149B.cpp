#include<iostream>
using namespace std;

long long a, b, k;
int main() {
	scanf("%lld %lld %lld", &a, &b, &k);
	long long t = min(a, k);
	a -= t;
	k -= t;
	t = min(b, k);
	b -= t;
	k -= t;
	printf("%lld %lld\n", a, b);
	return 0;
}
