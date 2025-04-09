#include<iostream>
using namespace std;

int n;
bool v[30];

int main() {
	string s;
	cin >> s;
	
	int n = s.size();
	bool can = !(n & 1);
	
	for (int i = 0; i < n / 2; i++) {
		can = can && (s[2 * i] == s[2 * i + 1]) && !v[s[2 * i] - 'a'];
		v[s[2 * i] - 'a'] = true;
	}
	
	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}