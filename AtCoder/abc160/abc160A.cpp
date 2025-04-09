#include<iostream>
#include<string>
using namespace std;

string S;
int main() {
	cin >> S;
	if (S[2] == S[3] && S[4] == S[5]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
