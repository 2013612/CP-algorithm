#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, ans;
string s;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		ans = 0;
		cin >> s;
		int cnt = 0;
		int people = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				cnt++;
			} else {
				cnt--;
			}
			people++;
			if (people > 1 && cnt > 0) {
				ans += cnt;
				cnt = 1;
				people = 1;
			}
			if (cnt < 0) {
				cnt = 0;
				people = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
