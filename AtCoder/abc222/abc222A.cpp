#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, ans;
string a;
int main() {
	cin >> a;
	while (a.length() != 4) {
		a = "0" + a;
	}
	cout << a << endl;
	return 0;
}
