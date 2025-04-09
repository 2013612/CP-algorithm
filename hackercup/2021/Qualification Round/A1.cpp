#include<iostream>
using namespace std;

int N;
int main() {
	freopen("consistency_chapter_1_input.txt", "r", stdin);
	freopen("consistency_chapter_1_output.txt", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		int vol = 0, con = 0;
		int a[26];
		for (int j = 0; j < 26; j++) {
			a[j] = 0;
		}
		for (auto x:s) {
			a[x - 'A']++;
			if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') {
				vol++;
			} else {
				con++;
			}
		}
		int ans = 1e9;
		for (int j = 0; j < 26; j++) {
			char x = 'A' + j;
			if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') {
				ans = min(ans, con + 2 * (vol - a[j]));
			} else {
				ans = min(ans, vol + 2 * (con - a[j]));
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
}
