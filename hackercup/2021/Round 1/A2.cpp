#include<iostream>
#include<vector>
using namespace std;

const int M = 1000000007;
int N, T;
int main() {
	freopen("weak_typing_chapter_2_input.txt", "r", stdin);
	freopen("weak_typing_chapter_2_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		string s;
		cin >> s;
		vector<long long> b = {0};
		vector<long long> c = {0};
		vector<long long> d = {0};
		vector<long long> e = {0};
		vector<long long> a[2] = {{0}, {0}};
		int now = -1;
		int last = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O') {
				now = 0;
				break;
			} else if (s[j] == 'X') {
				now = 1;
				break;
			}
		}
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'O' && now == 0) {
				last = j;
			}
			if (s[j] == 'X' && now == 1) {
				last = j;
			}
			if (s[j] == 'O' && now == 1) {
				now = 0;
				a[1 - now].push_back(last + 1);
				a[now].push_back(j + 1);
				last = j;
			}
			if (s[j] == 'X' && now == 0) {
				now = 1;
				a[1 - now].push_back(last + 1);
				a[now].push_back(j + 1);
				last = j;
			}
		}
		a[0].push_back(s.length() + 1);
		a[1].push_back(s.length() + 1);
		if (a[0][1] < a[1][1]) {
			now = 0;
		} else {
			now = 1;
		}
		for (int j = 1; j < a[0].size(); j++) {
			b.push_back(a[now][j] - a[1 - now][j - 1]);
			e.push_back(a[1 - now][j] - a[now][j - 1]);
			c.push_back(c[j - 1] + b[j]);
			d.push_back(d[j - 1] + c[j]);
			now = 1 - now;
		}
		long long ans = 0;
		for (int j = 2; j < e.size(); j++) {
			ans = (ans + e[j] * d[j - 1] % M) % M;
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}

