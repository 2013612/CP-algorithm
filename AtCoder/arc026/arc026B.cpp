#include<iostream>
using namespace std;

long long N, ans;
int main() {
	cin >> N;
	for (long long i = 1; i * i <= N; i++) {
		if (i * i == N) {
			ans += i;
		} else if (N % i == 0) {
			ans += i + N/i;
		}
	}
	ans -= N;
	if (ans < N) {
		cout << "Deficient" << endl;
	} else if (ans == N) {
		cout << "Perfect" << endl;
	} else {
		cout << "Abundant" << endl;
	}
	return 0;
}
