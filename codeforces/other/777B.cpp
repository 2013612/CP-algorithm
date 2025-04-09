#include<iostream>
using namespace std;

int N, M1[10], M2[10];
char S[1004];
int main() {
	scanf("%d", &N);
	scanf("%s", S);
	for (int i = 0; i < N; i++) {
		char temp;
		//scanf("%c", &temp);
		cin >> temp;
		M1[temp - '0']++;
		M2[temp - '0']++;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int temp = S[i] - '0';
		for (int j = temp; j <= 9; j++) {
			if (M1[j] >= 1) {
				M1[j]--;
				break;
			}
			if (j == 9) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	ans = 0;
	for (int i = 0; i < N; i++) {
		int temp = S[i] - '0';
		for (int j = temp + 1; j <= 9; j++) {
			if (M2[j] >= 1) {
				M2[j]--;
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
