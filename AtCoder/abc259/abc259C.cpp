#include<iostream>
using namespace std;

string s, t, ans;
int main() {
	cin >> s >> t;
	
	int i = 0, j = 0, cnt = 1;
	while (j < t.size()) {
		if (i == s.size() || s[i] != t[j]) {
			if (j > 0 && t[j] == t[j - 1] && cnt >= 2) {
				j++;
			} else {
				break;
			}
		} else {
			i++;
			j++;
		}
		
		if (j > 1 && t[j - 1] == t[j - 2]) {
			cnt++;
		} else {
			cnt = 1;
		}
	}
	
	if (i == s.size() && j == t.size()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
	return 0;
}