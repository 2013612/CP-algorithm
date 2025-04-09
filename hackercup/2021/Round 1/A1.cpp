#include<iostream>
using namespace std;

int N, T;
int main() {
	freopen("weak_typing_chapter_1_input.txt", "r", stdin);
	freopen("weak_typing_chapter_1_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		string s;
		cin >> s;
		int ans = 0;
		int now = -1;
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
			if (s[j] == 'O' && now == 1) {
				now = 0;
				ans++;
			}
			if (s[j] == 'X' && now == 0) {
				now = 1;
				ans++;
			}
		}
		printf("Case #%d: %d\n", i, max(ans, 0));
	}
	return 0;
}
