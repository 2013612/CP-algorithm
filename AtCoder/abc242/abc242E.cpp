#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int t;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		int n;
		string s;
		mint ans = 0;
		cin >> n >> s;
		if (n == 1) {
			printf("%d\n", s[0] - 'A' + 1);
			continue;
		}
		mint p = 1;
		for (int i = n / 2 - 1; i >= 0; i--) {
			if (s[i] < s[n - i - 1]) {
				ans++;
				break;
			} else if (s[i] > s[n - i - 1]) {
				break;
			}
			if (i == 0) {
				ans++;
			}
		}
		for (int i = 1; i <= (n + 1) / 2; i++) {
			ans += p * (s[(n + 1) / 2 - i] - 'A');
			p *= 26;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
