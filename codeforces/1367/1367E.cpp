#include<iostream>
#include<string>
using namespace std;

int T, N, K, a[103];
string S;

int gcd(int x, int y) {
	return y == 0? x: gcd(y, x % y);
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &K);
		cin >> S;
		int ans = 1;
		for (int j = 0; j < 30; j++) {
			a[j] = 0;
		}
		//cout << "!" << endl;
		for (int j = 0; j < N; j++) {
			a[S[j] - 'a']++;
		}
		//cout << "!" << endl;
		for (int j = 2; j <= N; j++) {
			int temp = gcd(K, j);
			int temp2 = j/temp;
			int cou = 0;
			for (int k = 0; k < 26; k++) {
				cou += a[k]/temp2;
			}
			if (cou >= temp) {
				ans = j;
			}
		}
		//cout << "!" << endl;
		printf("%d\n", ans);
	}
	return 0;
}
