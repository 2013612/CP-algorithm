#include<iostream>
#include<set>
using namespace std;

int n, m, k, a[503][503], moun[503][503], pre[503][503];
set<int> s;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void solve() {
	scanf("%d %d %d", &n, &m, &k);
	s.clear();
	long long diff = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			moun[i][j] = 0;
			moun[i + 1][j + 1] = 0;
			pre[i][j] = 0;
			pre[i + 1][j + 1] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '0') {
				moun[i][j] = -1;
			} else {
				moun[i][j] = 1;
			}
			diff += moun[i][j] * a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] - moun[i][j];
		}
	}
	
	for (int i = k; i <= n; i++) {
		for (int j = k; j <= m; j++) {
			int sum = pre[i][j] + pre[i - k][j - k] - pre[i][j - k] - pre[i - k][j];
			s.insert(abs(sum));
		}
	}
	
	s.erase(0);
	
	int g = 0;
	
	for (int temp: s) {
		g = gcd(temp, g);
	}
	
	if (diff == 0 || (g != 0 && diff % g == 0)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}