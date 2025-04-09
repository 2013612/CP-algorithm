#include<iostream>
using namespace std;

long long n;
int main() {
	scanf("%lld", &n);
	printf("%lld\n", n * (n - 1) / 2);
	return 0;
}
