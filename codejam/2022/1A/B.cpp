#include<iostream>
#include<algorithm>
using namespace std;

int t;

void solve() {
	int n, a[203];
	scanf("%d", &n);
	long long sum = (1 << 30) - 1;
	for (int i = 0; i <= 29; i++) {
		a[i] = (1 << i);
		cout << a[i] << " ";
	}
	for (int i = 30; i < n; i++) {
		a[i] = a[i - 1] + 1;
		sum += a[i];
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[100 + i]);
		sum += a[100 + i];
	}
	sort(a + 30, a + 200);
	long long half = sum / 2;
	for (int i = 2 * n - 1; half >= (1 << 30); i--) {
		if (half >= a[i]) {
			half -= a[i];
			cout << a[i] << " ";
		}
	}
	for (int i = 29; half > 0; i--) {
		if (half >= a[i]) {
			half -= a[i];
			cout << a[i] << " ";
		}
	}
	cout << endl;
}

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		solve();
	}
	return 0;
}
