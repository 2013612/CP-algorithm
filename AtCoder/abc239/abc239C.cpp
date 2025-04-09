#include<iostream>
using namespace std;

long long x1, y1, x2, y2;

long long p[10] = {2, 1, -1, -2, -2, -1, 1, 2};
long long q[10] = {1, 2, 2, 1, -1, -2, -2, -1};

bool dis(long long a, long long b) {
	long long t1 = (a - x2) * (a - x2);
	long long t2 = (b - y2) * (b - y2);
	return (t1 + t2) == 5;
}

int main() {
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	for (int i = 0; i < 8; i++) {
		if (dis(x1 + p[i], y1 + q[i])) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
