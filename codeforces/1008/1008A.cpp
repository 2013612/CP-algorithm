#include<iostream>
#include<string>
using namespace std;

string s;
bool v = true;
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++){
		if (v) {
			if (s[i] != 'a' && s[i] != 'o' && s[i] != 'u' && s[i] != 'i' && s[i] != 'e' && s[i] != 'n') {
				v = false;
			}
		} else {
			if (s[i] != 'a' && s[i] != 'o' && s[i] != 'u' && s[i] != 'i' && s[i] != 'e' && s[i] != 'n') {
				cout << "NO";
				return 0;
			} else {
				v = true;
			}
		}
		if (i == s.length() - 1 && (s[i] != 'a' && s[i] != 'o' && s[i] != 'u' && s[i] != 'i' && s[i] != 'e' && s[i] != 'n')) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
