#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;
string s[3], t[3], S, T;
int main() {
	cin >> s[0] >> s[1] >> s[2] >> t[0] >> t[1] >> t[2];
	if (s[0] != t[0]) {
		ans++;
		if (s[0] == t[1]) {
			swap(t[0], t[1]);
		} else {
			swap(t[0], t[2]);
		}
	}
	if (s[1] != t[1]) {
		ans++;
		swap(t[1], t[2]);
	}
	if (ans % 2) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
	return 0;
}
