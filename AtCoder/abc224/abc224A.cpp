#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string S;
int main() {
	cin >> S;
	if (S.back() == 'r') {
		cout << "er" << endl;
	} else {
		cout << "ist" << endl;
	}
	return 0;
}
