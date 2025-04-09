#include<iostream>
#include<unordered_set>
#include<math.h>
using namespace std;

long long n, ans;
unordered_set<long long> us;

bool is_square(long long a) {
	long long sq = floor(sqrt((long double)a));
	return sq * sq == a;
}

int main() {
	scanf("%lld", &n);
	
	ans = sqrt((long double)n);
	for (int i = 2; 1ll * i * i <= n / i; i++) {
		long long a = 1ll * i * i;
		while (a <= n / i && !us.count(a * i)) {
			a *= i;
			if (!is_square(a)) {
				us.insert(a);
			}
		}
	}
	
	printf("%lld\n", ans + us.size());
	
	return 0;
}