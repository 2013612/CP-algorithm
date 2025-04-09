#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, ans;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		string s, t;
		cin >> s >> t;
		ans = 0;
		for (int j = 0; j < N; j++) {
			if (t[j] == '0') {
				continue;
			}
			if (s[j] == '0') {
				ans++;
				s[j] = '2';
			} else {
				if (j != 0 && s[j - 1] == '1') {
					ans++;
					s[j - 1] = '2';
				} else if (j != N - 1 && s[j + 1] == '1') {
					ans++;
					s[j + 1] = '2';
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
