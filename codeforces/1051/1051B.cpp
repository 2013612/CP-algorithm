#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long l, r;
int main(){
	scanf("%lld %lld", &l, &r);
	printf("YES\n");
	for (long long i = l, j = l + 1; j <= r; i += 2, j += 2) {
		printf("%lld %lld\n", i, j);
	}
	return 0;
}
