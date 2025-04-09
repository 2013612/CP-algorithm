#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int main() {
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	cout << N/2 + 1 << endl;
	for (int i = 0; i < N/2 + 1; i++) {
		cout << 1 << " " << i + 1 << endl;
	}
	for (int i = 0; i < N - N/2 - 1; i++) {
		cout << i + 2 << " " << N/2 + 1 << endl;
	}
	return 0;
}
