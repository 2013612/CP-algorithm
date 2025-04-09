#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const string s = "sick", t = "fine";

int ans;
string s1, s2;

int main() {
	cin >> s1 >> s2;
	
	if (s1 == s) {
		if (s2 == s) {
			ans = 1;
		} else {
			ans = 2;
		}
	} else {
		if (s2 == s) {
			ans = 3;
		} else {
			ans = 4;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}