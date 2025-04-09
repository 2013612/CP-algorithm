#include<iostream>
#include<set>
using namespace std;

long long A, B, ans;
set<int> con;

long long gcd(long long a, long long b) {
	return b == 0? a : gcd(b, a % b);
}

void cal(int a) {
	for (auto x:con) {
		if (gcd(x, a) > 1) return;
	}
	ans++;
	con.insert(a);
	if (a + 1 <= B) {
		cal(a + 1);
	}
	con.erase(a);
}

int main() {
	scanf("%lld %lld", &A, &B);
	ans = 1;
	for (long long i = A; i <= B; i++) {
		cal(i);
	}
	printf("%lld\n", ans);
	return 0;
}
