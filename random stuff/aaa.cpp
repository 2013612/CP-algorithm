#include<iostream>
using namespace std;

int* a[100];
int main() {
	int b = 1;
	int c = 2;
	int d = 3;
	a[0] = &b;
	a[1] = &c;
	a[2] = &d;
	cout << a[0] << endl;
	cout << &a[0] << endl;
	cout << *a[0] << endl;
	return 0;
}
