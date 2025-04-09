#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, pos[3];
bool lower, upper, number;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		lower = upper = number = false;
		pos[0] = pos[1] = pos[2] = -1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				lower = true;
			} else if (s[i] >= 'A' && s[i] <= 'Z') {
				upper = true;
			} else {
				number = true;
			}
		}
		if (lower && upper && number) {
			cout << s << endl;
			continue;
		}
		if (!lower && !upper) {
			s[1] = 'a';
			s[2] = 'A';
			cout << s << endl;
			continue;
		}
		if (!number && !upper) {
			s[1] = '1';
			s[2] = 'A';
			cout << s << endl;
			continue;
		}
		if (!lower && !number) {
			s[1] = 'a';
			s[2] = '1';
			cout << s << endl;
			continue;
		}
		if (lower) {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] >= 'a' && s[i] <= 'z') {
					pos[0] = i;
					break;
				}
			}
		}
		if (upper) {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] >= 'A' && s[i] <= 'Z') {
					pos[1] = i;
					break;
				}
			}
		}
		if (number) {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] >= '0' && s[i] <= '9') {
					pos[2] = i;
					break;
				}
			}
		}
		if (!lower) {
			for (int i = 0; i < s.length(); i++) {
				if (i != pos[1] && i != pos[2]) {
					s[i] = 'a';
					break;
				}
			}
			cout << s << endl;
			continue;
		}
		if (!upper) {
			for (int i = 0; i < s.length(); i++) {
				if (i != pos[0] && i != pos[2]) {
					s[i] = 'A';
					break;
				}
			}
			cout << s << endl;
			continue;
		}
		if (!number) {
			for (int i = 0; i < s.length(); i++) {
				if (i != pos[1] && i != pos[0]) {
					s[i] = '1';
					break;
				}
			}
			cout << s << endl;
			continue;
		}
	}
	return 0;
}
