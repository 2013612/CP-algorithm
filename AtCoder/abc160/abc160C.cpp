#include<iostream>
using namespace std;

int K, N, a[200006], ans;
int main() {
	cin >> K >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	ans = a[0] + K - a[N - 1];
	for (int i = N - 1; i > 0; i--) {
		ans = max(ans, a[i] - a[i - 1]);
	}
	cout << K - ans << endl;
	return 0;
}
