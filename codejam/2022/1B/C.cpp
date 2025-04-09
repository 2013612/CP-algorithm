#include<iostream>
using namespace std;

string f(int a) {
	string s;
	for (int i = 7; i >= 0; i--) {
		if (a & (1 << i)) {
			s.push_back('1');
		} else {
			s.push_back('0');
		}
	}
	return s;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		int k;
		for (int i = 0; i < (1 << 8); i++) {
			cout << f(i) << endl;
			cin >> k;
			if (k == 0 || k == -1) {
				break;
			}
		}
		if (k == -1) {
			break;
		}
	}
	return 0;
}
