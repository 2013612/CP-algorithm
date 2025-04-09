#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int T;
string s, ans;
bool exist[30];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		cin >> s;
		ans.clear();
		for (int j = 0; j < 26; j++) {
			exist[j] = false;
		}
		ans = s[0];
		exist[s[0] - 'a'] = true;
		bool Done = true;
		for (int j = 1; j < s.length(); j++) {
			if (!exist[s[j] - 'a']) {
				if (ans.front() == s[j - 1]) {
					ans = s[j] + ans;
				} else if (ans.back() == s[j - 1]) {
					ans.push_back(s[j]);
				} else {
					Done = false;
					break;
				}
				exist[s[j] - 'a'] = true;
			} else {
				int count = 0;
				for (int k = 0; k < ans.length(); k++) {
					if (ans[k] == s[j - 1]) {
						count = k;
						break;
					}
				}
				if (count == 0) {
					if (ans[1] != s[j]) {
						Done = false;
						break;
					} else {
						continue;
					}
				}
				if (count == ans.length() - 1) {
					if (ans[count - 1] != s[j]) {
						Done = false;
						break;
					} else {
						continue;
					}
				}
				if (ans[count - 1] != s[j] && ans[count + 1] != s[j]) {
					Done = false;
					break;
				}
			}
		}
		if (!Done) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			cout << ans;
			for (int j = 0; j < 26; j++) {
				if (!exist[j]) {
					cout << char('a' + j);
				}
			}	
		}
		cout << endl;
	}
	return 0;
}
