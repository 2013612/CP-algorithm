#include<iostream>
using namespace std;

int n, one, two, ans, mode;

int main() {
	scanf("%d", &n);
	string s;
	cin >> s;
	
	for (int i = 0; i < n; i++) {
		if (mode == 0) {
			if (s[i] == '1') {
				one++;
			} else if (s[i] == '/') {
				mode = 1;
			} else {
				one = 0;
			}
		} else {
			if (s[i] == '1') {
				ans = max(ans, min(one, two) * 2 + 1);
				one = 1;
				two = 0;
				mode = 0;
			} else if (s[i] == '/') {
				ans = max(max(ans, 1), min(one, two) * 2 + 1);
				one = 0;
				two = 0;
				mode = 0;
			} else {
				two++;
			}
		}
	}
	
	if (mode == 1) {
		ans = max(max(ans, 1), min(one, two) * 2 + 1);
	}
	
	printf("%d\n", ans);
	
	return 0;
}