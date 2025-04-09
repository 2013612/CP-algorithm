#include<iostream>
using namespace std;

int T, R, C, K;
string s[2000007];
int cnt[2000007];
int main() {
	freopen("valet_parking_chapter_1_input.txt", "r", stdin);
	freopen("valet_parking_chapter_1_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d", &R, &C, &K);
		int ans = 0;
		for (int j = 1; j <= R; j++) {
			cin >> s[j];
		}
		for (int j = 0; j < C; j++) {
			cnt[j] = 0;
			if (s[K][j] =='X') {
				ans++;
			}
		}
		for (int j = 1; j <= K; j++) {
			for (int k = 0; k < C; k++) {
				if (s[j][k] == 'X') {
					cnt[k]++;
				}
			}
		}
		for (int j = 1; j <= R - K + 1; j++) {
			if (j >= ans) {
				break;
			}
			int temp = 0;
			for (int k = 0; k < C; k++) {
				if (cnt[k] >= K) {
					temp++;
				} else if (K + j <= R && s[K + j][k] == 'X') {
					temp++;
					cnt[k]++;
				}
			}
			ans = min(ans, temp + j);
		}
		for (int j = 0; j < C; j++) {
			cnt[j] = 0;
		}
		for (int j = K; j <= R; j++) {
			for (int k = 0; k < C; k++) {
				if (s[j][k] == 'X') {
					cnt[k]++;
				}
			}
		}
		for (int j = 1; j <= K; j++) {
			if (j >= ans) {
				break;
			}
			int temp = 0;
			for (int k = 0; k < C; k++) {
				if (cnt[k] >= R - K + 1) {
					temp++;
				} else if (K - j > 0 && s[K - j][k] == 'X') {
					temp++;
					cnt[k]++;
				}
			}
			ans = min(ans, temp + j);
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}

