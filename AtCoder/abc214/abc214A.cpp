#include<iostream>
using namespace std;

int N;
int main() {
	cin >> N;
	if (N <= 125) {
		cout << 4 << endl;
	} else if (N <= 211) {
		cout << 6 << endl;
	} else {
		cout << 8 << endl;
	}
	return 0;
}
