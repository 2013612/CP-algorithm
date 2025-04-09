#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long ans, a[3];
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + 3);
	long long diff1 = a[1] - a[0];
	ans += diff1;
	a[2] -= diff1;
	a[1] -= diff1;
	long long diff2 = a[2] - a[0];
	ans += diff2 * 2;
	a[2] -= diff2 * 2;
	a[1] -= diff2;
	a[0] -= diff2;
	if (a[0] < 0) {
		printf("-1\n");
	} else {
		printf("%lld\n", ans + a[0]);
	}
	return 0;
}