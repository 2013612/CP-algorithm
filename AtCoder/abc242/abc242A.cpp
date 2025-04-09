#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a, b, c, x;
double ans;
int main() {
	scanf("%d %d %d %d", &a, &b, &c, &x);
	if (x <= a) {
		ans = 1;
	} else if (x <= b) {
		ans = (double) c / (b - a);
	} else {
		ans = 0;
	}
	printf("%.9lf\n", ans);
	return 0;
}
