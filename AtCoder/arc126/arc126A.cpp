#include<iostream>
using namespace std;

int T;
long long a[100];
int main() {
	scanf("%d", &T);
	while (T-- > 0) {
		for (int i = 0; i < 20; i++) {
			a[i] = 0;
		}
		scanf("%lld %lld %lld", &a[2], &a[3], &a[4]);
		a[6] = a[3] / 2;
		long long temp = min(a[4], a[6]);
		a[10] = temp;
		a[4] -= temp;
		a[6] -= temp;
		if (a[6] > 0) {
			temp = min(a[6], a[2] / 2);
			a[10] += temp;
			a[6] -= temp;
			a[2] -= 2 * temp;
		} else if (a[4] > 0) {
			a[8] = a[4] / 2;
			temp = min(a[8], a[2]);
			a[10] += temp;
			a[8] -= temp;
			a[2] -= temp;
			if ((a[4] & 1) && a[2] >= 3) {
				a[10]++;
				a[4]--;
				a[2] -= 3;
			}
		}
		a[10] += a[2] / 5;
		printf("%lld\n", a[10]);
	}
}
