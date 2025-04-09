#include<iostream>
#include<string>
using namespace std;

string S;
bool par1, par2, nq;
int main() {
	cin >> S;
	if (S.length() == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < S.length()/2; i++) {
		if (S[i] != S[S.length() - 1 - i]) {
			if (!nq) {
				nq = true;
			} else {
				break;
			}
		}
		if (i == S.length()/2 - 1) {
			if (!nq) {
				par1 = true;
			} else {
				par2 = true;
			}
		}
	}
	if (par1) {
		cout << S.length()/2*2*25 << endl;
	} else if (par2) {
		cout << S.length()*25 - 2 << endl;
	} else {
		cout << S.length()*25 << endl;
	}
	return 0;
}
