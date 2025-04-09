#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt += s[i] <= 'Z';
	}
	
	string t;
	for (int i = 0; i < s.size(); i++) {
		if (cnt > s.size() / 2) {
			if (s[i] <= 'Z') {
				t.push_back(s[i]);
			} else {
				t.push_back(s[i] ^ 32);
			}
		} else {
			t.push_back((char)(s[i] | 32));
		}
	}
	
	cout << t << endl;
	
	return 0;
}