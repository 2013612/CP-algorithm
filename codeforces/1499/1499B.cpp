#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		for (int j = 0; j <= s.length(); j++) {
			bool success = true;
			vector<int> zero, one;
			for (int k = 0; k < j; k++) {
				if (s[k] == '1') {
					one.push_back(k);
				}
			}
			for (int k = j; k < s.length(); k++) {
				if (s[k] == '0') {
					zero.push_back(k);
				}
			}
			for (int k = 1; k < zero.size(); k++) {
				if (zero[k] - zero[k - 1] < 2) {
					success = false;
					break;
				}
			}
			for (int k = 1; k < one.size(); k++) {
				if (one[k] - one[k - 1] < 2) {
					success = false;
					break;
				}
			}
//			if (one.size() && zero.size() && one.back() - zero.front() < 2) {
//				success = false;
//			}
			if (success) {
				printf("YES\n");
				break;
			}
			if (!success && j == s.length()) {
				printf("NO\n");
			}
		}
	}
	return 0;
}
