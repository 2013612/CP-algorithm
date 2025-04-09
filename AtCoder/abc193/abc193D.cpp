#include<iostream>
using namespace std;

int K, a[103];
string S, T;
string num = "0123456789";
double ans;

int cal(string x) {
	int a[12], score;
	score = 0;
	for (int i = 1; i <= 9; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < 5; i++) {
		a[x[i] - '0']++;
	}
	for (int i = 1; i <= 9; i++) {
		int temp = i;
		for (int j = 0; j < a[i]; j++) {
			temp *= 10;
		}
		score += temp;
	}
	return score;
}

int main() {
	scanf("%d", &K);
	cin >> S >> T;
	for (int i = 1; i <= 9; i++) {
		a[i] = K;
	}
	S = S.substr(0, 4);
	T = T.substr(0, 4);
	for (int i = 0; i < 4; i++) {
		a[S[i] - '0']--;
		a[T[i] - '0']--;
	}
	for (int i = 1; i <= 9; i++) {
		if (a[i] == 0) {
			continue;
		}
		a[i]--;
		for (int j = 1; j <= 9; j++) {
			if (a[j] > 0) {
				if (cal(S + num[i]) > cal(T + num[j])) {
					ans += (double) (a[i] + 1) * a[j] / (9 * K - 8) / (9 * K - 9);
				}
			}
		}
		a[i]++;
	}
	printf("%.10f\n", ans);
	return 0;
}
