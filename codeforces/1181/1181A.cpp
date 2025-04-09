#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

long long x, y, z;
int main(){
	scanf("%lld %lld %lld", &x, &y, &z);
	printf("%lld ", (x + y) / z);
	long long a = x % z;
	long long b = y % z;
	if (a + b >= z) {
		printf("%lld\n", min(z - a, z - b));
	} else {
		printf("0\n");
	}
	return 0;
}
