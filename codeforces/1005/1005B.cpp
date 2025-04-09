#include<iostream>
#include<string>
using namespace std;

string s, t, a, b;
char c;
int main(){
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++) {
		c = *(s.rbegin() + i);
		a.push_back(c);
	}
	for (int i = 0; i < t.length(); i++) {
		c = *(t.rbegin() + i);
		b.push_back(c);
	}
	int num = 0;
	for (int i = 0; i < max(s.length(), t.length()); i++) {
		if (a[i] != b[i]) {
			num = i;
			break;
		}
	}
	if (a == b) {
		cout << 0;
		return 0;
	}
	cout << s.length() + t.length() - 2*num;
	return 0;
}
