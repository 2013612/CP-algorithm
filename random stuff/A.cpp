#include<iostream>
using namespace std;

int R;
int main() {
	cin >> R;
	if (R < 1200) cout << "ABC" << endl;
	else if (R >= 1200 && R < 2800) cout << "ARC" << endl;
	else if (R >= 2800) cout << "AGC" << endl;
	return 0;
}
