#include<iostream>
using namespace std;

int n, m;
long long a[1003][1003];
string s;

void solve() {
	scanf("%d %d", &n, &m);
	
	cin >> s;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lld", &a[i][j]);
		}
	}

	int r = 0;
	int c = 0;
	
	for (int i = 0; i < s.size(); i++) {
		long long sum = 0;
		if (s[i] == 'D') {
			for (int j = 0; j < m; j++) {
				sum += a[r][j];
			}
		} else {
			for (int j = 0; j < n; j++) {
				sum += a[j][c];
			}
		}
		
		a[r][c] = -sum;
		
		if (s[i] == 'D') {
			r++;
		} else {
			c++;
		}
	}
	
	for (int i = 0; i < m - 1; i++) {
		a[n - 1][m - 1] -= a[n - 1][i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%lld ", a[i][j]);
		}
		printf("\n");
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