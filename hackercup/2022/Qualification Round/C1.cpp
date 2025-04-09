#include<iostream>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	char c;
	if (s.back() == '.') {
		c = '-';
	} else {
		c = '.';
	}
	for (int i = 0; i < n - 1; i++) {
		s.push_back(c);
		cout << s << endl;
	}
}

int main() {
	freopen("second_meaning_input.txt", "r", stdin);
	freopen("second_meaning_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: \n", i);
		solve();
	}
	
	return 0;
}