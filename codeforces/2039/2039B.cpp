#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, a[200006], ans;

void solve() {
	string s;
	cin >> s;
	
	n = s.size();
	
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			printf("%c%c\n", s[i], s[i + 1]);
			return;
		}
	}
	
	for (int i = 0; i < n - 2; i++) {
		if (s[i] != s[i + 2]) {
			printf("%c%c%c\n", s[i], s[i + 1], s[i + 2]);
			return;
		}
	}
	
	printf("-1\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}