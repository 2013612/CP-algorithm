#include<iostream>
using namespace std;

long long N, ans, a[20], b[20];

long long cal(long long x) {
	//cout << x << endl;
	if (x == 0) {
		return 0;
	}
	long long digit = 1;
	int cnt = 1;
	while (x / digit > 0) {
		digit *= 10;
		cnt++;
	}
	digit /= 10;
	if (x / digit > 1) {
		return b[cnt - 1];
	} else {
		return b[cnt - 2] + x % digit + 1 + cal(x % digit);
	}
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i < 18; i++) {
		a[i] = a[i - 1] * 10 + 1;
		b[i] = b[i - 1] + a[i];
	}
	cout << cal(99) << endl;
	cout << cal(20) << endl;
	printf("%lld\n", cal(N));
	return 0;
}
