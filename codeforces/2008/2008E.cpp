#include<iostream>
using namespace std;

int a[200006][30], b[200006][30];

void solve() {
	int n;
	scanf("%d", &n);
	
	string s;
	cin >> s;
	
	for (int j = 0; j <= n; j++) {
		for (int i = 0; i < 26; i++) {
			a[j][i] = b[j][i] = 0;
		}
	}
	
	for (int i = 1; i <= n; i += 2) {
		a[i][s[i - 1] - 'a']++;
	}
	
	for (int i = 2; i <= n; i += 2) {
		b[i][s[i - 1] - 'a']++;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			a[i][j] += a[i - 1][j];
			b[i][j] += b[i - 1][j];
		}
	}
	
	int ans = 1e9;
	
	if (n & 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) {
				for (int k = 0; k < 26; k++) {
					int odd = a[i - 1][j] + b[n][j] - b[i][j];
					int even = b[i - 1][k] + a[n][k] - a[i][k];
					ans = min(ans, n - 1 - odd - even);
				}
			}
		}
		
		ans++;
	} else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				ans = min(ans, n - a[n][i] - b[n][j]);
			}
		}
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}