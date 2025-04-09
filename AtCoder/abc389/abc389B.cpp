#include<iostream>
using namespace std;

int main() {
	long long x;
	scanf("%lld", &x);
	
	long long y = 1;
	for (int i = 2; i < 10000; i++) {
		y *= i;
		if (y == x) {
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}