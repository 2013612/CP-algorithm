#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string S,T;
bool success;
int main(){
	cin >> S >> T;
	int num = S.length();
	for (int i = 0; i < num; i++) {
		bool success1 = true;
		for (int j = 0; j < num; j++) {
			int k = (i + j) % num;
			if (S[j] != T[k]) {
				success1 = false;
				break;
			}
		}
		if (success1) {
			success = true;
			break;
		}
	}
	if (success) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
