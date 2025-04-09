#include<iostream>
using namespace std;

int T;
int main() {
	freopen("xs_and_os_input.txt", "r", stdin);
	freopen("xs_and_os_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int N;
		scanf("%d", &N);
		string s[N];
		for (int j = 0; j < N; j++) {
			cin >> s[j];
		}
		int cou = 1e9;
		int ans = 0;
		int h[N], v[N];
		for (int j = 0; j < N; j++) {
			int temp = 0;
			for (int k = 0; k < N; k++) {
				if (s[j][k] == '.') {
					temp++;
				} else if (s[j][k] == 'O') {
					h[j] = -1;
					break;
				}
				if (k == N - 1) {
					h[j] = temp;
					if (temp == cou) {
						ans++;
					} else if (temp < cou) {
						cou = temp;
						ans = 1;
					}
				}
			}
			int temp2 = 0;
			for (int k = 0; k < N; k++) {
				if (s[k][j] == '.') {
					temp2++;
				} else if (s[k][j] == 'O') {
					v[j] = -1;
					break;
				}
				if (k == N - 1) {
					v[j] = temp;
					if (temp2 == cou) {
						ans++;
					} else if (temp2 < cou) {
						cou = temp2;
						ans = 1;
					}
				}
			}
		}
		if (cou == 1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (h[i] == 1 && v[j] == 1 && s[i][j] == '.') {
						ans--;
					}
				}
			}
		}
		if (ans == 0) {
			printf("Case #%d: Impossible\n", i);
		} else {
			printf("Case #%d: %d %d\n", i, cou, ans);
		}
	}
	return 0;
}
