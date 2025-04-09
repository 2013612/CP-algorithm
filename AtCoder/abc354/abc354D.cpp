#include<iostream>
using namespace std;

const int x[4][2] = {{2, 1}, {1, 2}, {0, 1}, {1, 0}};

const long long M = 2e9;

long long a, b, c, d, ans;

int main() {
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	
	ans = (c - a) / 4 * 4 * (d - b);
	for (int i = 0; i < (c - a) % 4; i++) {
		ans += x[(a + M + i) % 4][abs(b) % 2] * ((d - b + 1) / 2) + x[(a + M + i) % 4][1 - abs(b) % 2] * ((d - b) / 2);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}