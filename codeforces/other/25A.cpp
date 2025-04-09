#include<iostream>
using namespace std;

int N, a[203], sum;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		a[i] = a[i] % 2;
		sum += a[i];
	}
	if (sum == 1) {
		for (int i = 0; i < N; i++) {
			if (a[i] == 1) {
				cout << i + 1 << endl;
				break;
			}
		}
	} else {
		for (int i = 0; i < N; i++) {
			if (a[i] == 0) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}
