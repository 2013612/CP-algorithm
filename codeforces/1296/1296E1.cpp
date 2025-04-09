#include<iostream>
#include<string>
using namespace std;

int N, a[1004];
string s;
int main() {
	scanf("%d", &N);
	cin >> s;
	a[0] = -1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (s[i] < s[j]) {
				//cout << "!" << i << "" << j;
				if (a[i] == 0) {
					a[i] = a[j] * (-1);
				} else if (a[i] == a[j]) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		if (a[i] == 0) {
			a[i] = -1;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < N; i++) {
		if (a[i] == -1) {
			cout << 0;
		} else {
			cout << 1;
		}
	}
	cout << endl;
	return 0;
}
