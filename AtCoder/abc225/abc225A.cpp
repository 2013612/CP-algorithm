#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int ans;
int main() {
	string s;
	cin >> s;
	set<char> a;
	for (int i = 0; i < 3; i++) {
		a.insert(s[i]);
	}
	if (a.size() == 3) {
		ans = 6;
	} else if (a.size() == 2) {
		ans = 3;
	} else {
		ans = 1;
	}
	printf("%d\n", ans);
	return 0;
}
