#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

long long T;
int main() {
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (a == b) {
			printf("0 0\n");
		} else {
			long long temp = a % abs(a - b);
			long long ans = min(temp, abs(a - b) - temp);
			printf("%lld %lld\n", abs(a - b), ans);
		}
	}
	return 0;
}
