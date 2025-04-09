#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int x, y, z;
int main() {
	cin >> x >> y >> z;
	if (x - y > z) {
		cout << "+" << endl;
	} else if (y - x > z) {
		cout << "-" << endl;
	} else if (x == y && z == 0) {
		cout << "0" << endl;
	} else {
		cout << "?" << endl;
	}
	return 0;
}
