#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long n, a, b, p, q, r, s;
int main() {
	scanf("%lld %lld %lld", &n, &a, &b);
	scanf("%lld %lld %lld %lld", &p, &q, &r, &s);
	long long t1 = max(1 - a, 1 - b);
	long long t2 = min(n - a, n - b);
	long long t3 = max(1 - a, b - n);
	long long t4 = min(n - a, b - 1);
	//printf("%lld %lld\n", t1, t2);
	//printf("%lld %lld\n", t3, t4);
	for (long long i = p; i <= q; i++) {
		for (long long j = r; j <= s; j++) {
			if (i - a == j - b && t1 <= i - a && i - a <= t2) {
				printf("#");
			} else if (i - a == b - j && t3 <= i - a && i - a <= t4) {
				printf("#");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
