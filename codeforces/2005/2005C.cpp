#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const string K = "narek";

int dp[2003][5], ans;
int n, m;
string s[2003];

void gen() {
	n = rand() % 10;
	m = rand() % 10;
	for (int i = 1; i <= n; i++) {
		s[i] = "";
		for (int j = 0; j < m; j++) {
			s[i].push_back('a' + rand() % 26);
		}
	}
}

bool valid(char c) {
	bool can = false;
	for (int i = 0; i < K.size(); i++) {
		can = can || (c == K[i]);
	}
	return can;
}

void solve() {
//	gen()
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			dp[i][j] = -1e9;
		}
	}
	
	ans = 0;
	
	dp[0][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			string temp = K.substr(0, j);
			int cnt1 = 0;
			int cnt2 = 0;
			for (int k = 0; k < s[i].length(); k++) {
				if (s[i][k] == K[temp.size()]) {
					temp.push_back(s[i][k]);
				}
				
				if (valid(s[i][k])) {
					cnt2++;
				}
				
				if (temp == K) {
//					printf("%d %d %d\n", i, j, k);
					cnt1 += 5;
					cnt2 -= 5;
					temp = "";
				}
			}
//			printf("! %d %d %d %d %d\n", i, j, temp.size(), dp[i][temp.size()], dp[i - 1][j] + cnt1 - cnt2);
			dp[i][temp.size()] = max(dp[i][temp.size()], dp[i - 1][j] + cnt1 - cnt2);
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < 5; j++) {
//			printf("%d ", dp[i][j]);
//		}
//		printf("\n");
//	}
	
	for (int j = 0; j < 5; j++) {
		ans = max(ans, dp[n][j]);
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