#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string s[10], t[10];
int main() {
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	t[0] = "H";
	t[1] = "2B";
	t[2] = "3B";
	t[3] = "HR";
	sort(t, t + 4);
	sort(s, s + 4);
	if (t[0] == s[0] && t[1] == s[1] && t[2] == s[2] && t[3] == s[3]) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
