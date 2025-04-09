#include<iostream>
#include<cmath>
using namespace std;

const double PI = 3.14159265;

int a, b, d;
int main() {
	scanf("%d %d %d", &a, &b, &d);
	double r = sqrt(a * a + b * b);
	double rad = atan2(b, a) + (double) d / 180 * PI;
	printf("%.9f %.9f\n", r * cos(rad), r * sin(rad));
	return 0;
}