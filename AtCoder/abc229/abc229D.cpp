#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans, k;
string s;
int main() {
	cin >> s >> k;
	int left = 0, right = 0;
	int cou = 0;
	while (right <= s.size()) {
		if (cou == k + 1) {
			ans = max(ans, right - left - 1);
			if (s[left] == '.') {
				cou--;
			}
			left++;
		} else {
			if (s[right] == '.') {
				cou++;
			}
			right++;
		}
	}
	ans = max(ans, right - left - 1);
	printf("%d\n", ans);
	return 0;
}
