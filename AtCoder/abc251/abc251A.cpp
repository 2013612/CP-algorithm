#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, a[200006];
int main() {
	string s;
	cin >> s;
	string ans = s;
	while (ans.length() < 6) {
		ans = ans + s;
	}
	cout << ans << endl;
	return 0;
}