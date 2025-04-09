#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, t;
long long ans;
string s;

void solve() {
	scanf("%d", &n);
	cin >> s;
	ans = 0;
	for (int i = 0; i < n; i++) {
		int p = 0, m = 0, a = 0, cnt = 0;
		for (int j = i; j < n; j++) {
			if (s[j] == '+') {
				p++;
				cnt = 0;
			} else {
				m++;
				cnt++;
			}
			if (cnt > 0 && cnt % 2 == 0) {
				a++;
			}
			if (p + a >= m - 2 * a && p <= m && (p - m) % 3 == 0) {
				ans++;
			}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &t);
	while (t-- > 0)  {
		solve();
	}
	return 0;
}
