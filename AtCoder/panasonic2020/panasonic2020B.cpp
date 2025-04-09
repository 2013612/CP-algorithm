#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long H, W;
int main() {
	scanf("%lld %lld", &H, &W);
	if (H == 1 || W == 1) {
		printf("1\n");
		return 0;
	}
	printf("%lld\n", (H * W + 1) / 2);
	return 0;
}
