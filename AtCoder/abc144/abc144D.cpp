#include<iostream>
#include<math.h>
using namespace std;

const double PI = 3.14159265;

int a, b, x;
int main() {
	scanf("%d %d %d", &a, &b, &x);
	double ans;
	if (2 * x >= a * a * b) {
		ans = atan(((double) a * a * b - x) * 2 / a / a / a) * 180 / PI;
	} else {
		ans = atan(b / ((double) x * 2 / b / a)) * 180 / PI;
	}
	printf("%.9f\n", ans);
	return 0;
}
