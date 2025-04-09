#include<iostream>
using namespace std;

long long X;
int main() {
	cin >> X;
	long long quo = X / 500;
	long long rem = (X % 500) / 5;
	cout << quo * 1000 + rem * 5 << endl;
	return 0;
}
