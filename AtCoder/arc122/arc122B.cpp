#include<iostream>
using namespace std;

const long double diff = 1e-10;
int N, a[100006];
long double ans;

long double sum(long double x) {
	long double temp = x * N;
	for (int i = 0; i < N; i++) {
		temp += max(a[i] - 2 * x, (long double)0);
	}
	//cout << temp << endl;
	//printf("s %.9f", temp);
	return temp;
}

int main() {
	cout.precision(30);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	long double left = 0;
	long double right = 2e9;
	ans = 1e18;
	while (right - left > diff) {
		long double mid = (right + left) / 2;
		//cout << "m" << mid << endl;
		long double x1 = sum(mid - diff);
		long double x2 = sum(mid);
		long double x3 = sum(mid + diff);
		//printf("%.9f %.9f %.9f\n", x1, x2, x3);
		//cout << x1 << " " << x2 << " " << x3 << endl;
		if (x1 > x2 && x3 > x2) {
			ans = x2;
			break;
		} else if (x1 > x2 && x2 > x3) {
			left = mid;
			ans = min(ans, x3);
		} else {
			right = mid;
			ans = min(ans, x1);
		}
	}
	
	cout << ans / N << endl;
	//printf("%.9f\n", ans / N);
	return 0;
}
