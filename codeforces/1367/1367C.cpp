#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int T, N, ans, K;
string S;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &K);
		cin >> S;
		bool one = false;
		ans = 0;
		int ind = -1;
		for (int j = 0; j < N; j++) {
			if (S[j] == '1') {
				one = true;
			}
		}
		bool fr = false;
		bool ba = false;
		for (int j = 0; j <= K; j++) {
			if (S[j] == '1') {
				ind = j;
				break;
			}
			if (j == K) {
				fr = true;
			}
		}
		for (int j = N - 1; j >= N - K - 1; j--) {
			if (S[j] == '1') {
				break;
			}
			if (j == N - K - 1) {
				ba = true;
			}
		}
		if (!one) {
			ans = (N - 1)/(K + 1) + 1;
		} else {
			int cou = 0;
			if (fr) {
				S[0] = '1';
				ind = 0;
				ans++;
			}
			if (ba) {
				S[N - 1] = '1';
				ans++;
			}
			for (int j = ind; j < N; j++) {
				if (S[j] == '1') {
					cou = 0;
				} else {
					if (cou == 2*K) {
						ans++;
						cou = K;
					} else {
						cou++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
