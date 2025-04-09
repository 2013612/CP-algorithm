#include<iostream>
using namespace std;

bool check(string s, int sqrt) {
	bool can = true;
	for (int i = 0; i < sqrt; i++) {
		for (int j = 0; j < sqrt; j++) {
			if (i == 0 || i == sqrt - 1 || j == 0 || j == sqrt - 1) {
				can = can && (s[i * sqrt + j] == '1');
			} else {
				can = can && (s[i * sqrt + j] == '0');
			}
		}
	}
	
	return can;
}

void solve() {
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	
	for (int i = 2; i * i <= s.size(); i++) {
		if (i * i == s.size()) {
			if (check(s, i)) {
				printf("Yes\n");
				return;
			}
		}
	}
	
	printf("No\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}