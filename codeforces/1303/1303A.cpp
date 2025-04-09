#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int T, ans;
string s;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		cin >> s;
		bool start = false;
		int count = 0;
		ans = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '1') {
				if (!start) {
					start = true;
				} else {
					ans += count;
					count = 0;
				}
			} else {
				if (start) {
					count++;
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
