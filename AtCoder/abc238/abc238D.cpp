#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t;
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		long long a, s;
		scanf("%lld %lld", &a, &s);
		long long b = a + a;
		bool can = true;
		for (int j = 0; j < 61 && ((1ll << j) <= s); j++) {
			long long k = 1ll << j;
			if (s & k) {
				if (!(b & k)) {
					if (a & k) {
						can = false;
						break;
					} else {
						b += k;
					}
				}
			} else {
				if (b & k) {
					if (a & k) {
						can = false;
						break;
					} else {
						b += k;
					}
				}
			}
		}
		if (b != s) {
			can = false;
		}
		if (can) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
