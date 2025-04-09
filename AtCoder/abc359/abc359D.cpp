#include<iostream>
using namespace std;

const int M = 998244353;

int n, k, dp[2000][2000];
string s;

bool is_pal(string s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	
	return true;
}

int to_int(string s) {
	int a = 0;
	for (int i = 0; i < s.size(); i++) {
		a = (a << 1) + (s[i] == 'B');
	}
	return a;
}

string to_str(int a) {
	string s = string(k, ' ');
	for (int i = k - 1; i >= 0; i--) {
		s[i] = (char)('A' + (a & 1));
		a >>= 1;
	}
	return s;
}

void init(string cur) {
	if (cur.size() == k - 1) {
		dp[cur.size()][to_int(cur)]++;
		return;
	}
	
	if (s[cur.size()] != 'A') {
		init(cur + "B");
	}
	
	if (s[cur.size()] != 'B') {
		init(cur + "A");
	}
}

void add(int pos, int extra) {
	for (int j = 0; j < (1 << (k - 1)); j++) {
		int to = j * 2 + extra;
		string s = to_str(to);
		if (is_pal(s)) {
			continue;
		}
		
		dp[pos + 1][to_int(s.substr(1))] += dp[pos][j];
		dp[pos + 1][to_int(s.substr(1))] %= M;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	
	cin >> s;
	init("");
	
	for (int i = k - 1; i < n; i++) {
		if (s[i] != 'A') {
			add(i, 1);
		}
		
		if (s[i] != 'B') {
			add(i, 0);
		}
	}
	
	int ans = 0;
	for (int i = 0; i < (1 << (k - 1)); i++) {
		ans += dp[n][i];
		ans %= M;
	}
	
	printf("%d\n", ans);
	
	return 0;
}