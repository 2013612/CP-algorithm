#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int, int> pii;

int n, t;
long long ans;
string s;
map<pii, long long> mem[100006];

void solve() {
	scanf("%d", &n);
	cin >> s;
	ans = 0;
	int a = 0, p = 0, m = 0;
	for (int i = 0; i <= n; i++) {
		mem[i].clear();
	}
	mem[0][{0, 0}] = 1;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+') {
			p++;
			cnt = 0;
		} else {
			m++;
			cnt++;
		}
		if (cnt > 0 && cnt % 2 == 0) {
			a++;
		}
		for (int j = 0; j <= a; j++) {
			for (auto x : mem[j]) {
				int dp = x.first.first - p;
				int dm = x.first.second - m;
				int c = a - j;
				if (dp + c >= dm - 2 * c && dp <= dm && (dp - dm) % 3 == 0) {
					ans += x.second;
				}
			}
		}
		mem[a][{p, m}]++;
		printf("%d %d %d\n", p, m, a);
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
