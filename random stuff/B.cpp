#include<iostream>
#include<string>
using namespace std;

string R;
bool success = true;
int main() {
	cin >> R;
	int num = 0;
	for (int i = 0; i < R.length(); i++){
		if (i == 0 && R[i] != 'A'){
			success = false;
			break;
		} else if ((i == 1 || i == R.length()-1) && (R[i] >= 'A' && R[i] <= 'Z')) {
			success = false;
			break;
		} else if ((i > 1 && i < R.length() - 1) && (R[i] >= 'A' && R[i] <= 'Z') && R[i] != 'C'){
			success = false;
			break;
		}
		if (R[i] == 'C') num++;
	}
	if (num == 1 && success) {
		cout << "AC" << endl;
	} else {
		cout << "WA" << endl;
	}
	return 0;
}
