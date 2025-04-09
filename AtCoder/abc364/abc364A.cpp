#include<iostream>
using namespace std;

int n;
string ans = "Yes", s[103];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (i != 0 && i != n - 1 && s[i] == s[i - 1] && s[i] == "sweet") {
			ans = "No";
		}
	}
	
	cout << ans << endl;
	
	return 0;
}