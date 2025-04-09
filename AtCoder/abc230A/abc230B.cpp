#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string a = "oxxoxxoxxoxxoxxoxx";
string s;
bool can = false;
int main() {
	cin >> s;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < s.length(); j++) {
			if (a[i + j] != s[j]) {
				break;
			}
			if (j == s.length() - 1) {
				can = true;
				break;
			}
		}
	}
	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
