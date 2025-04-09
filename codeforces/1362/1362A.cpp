#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long N, ans, two[103];
int main() {
	scanf("%lld", &N);
	two[0] = 1;
	for (int i = 1; i <= 62; i++) {
		two[i] = two[i - 1] * 2;
	}
	for (int i = 0; i < N; i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (a > b) {
			long long temp = a;
			a = b;
			b = temp;
		}
		if (b % a == 0) {
			long long k = b / a;
			long long temp = -1;
			for (int j = 0; j <= 62; j++) {
				if (k == two[j]) {
					temp = j;
					break;
				}
			}
			if (temp == -1) {
				ans = -1;
			} else {
				if (temp % 3 == 0) {
					ans = temp/3;
				} else {
					ans = temp/3 + 1;
				}
			}
		} else {
			ans = -1;
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
