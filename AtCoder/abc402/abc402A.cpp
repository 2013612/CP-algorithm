#include<bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			t.push_back(s[i]);
		}
	}
	
	cout << t << endl;
	return 0;
}