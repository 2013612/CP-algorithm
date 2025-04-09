#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long T, r, b, d;
int main() {
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld %lld %lld", &r, &b, &d);
		if ((d + 1) * r >= b && (d + 1) * b >= r) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
