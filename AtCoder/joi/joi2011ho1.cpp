#include<iostream>
using namespace std;

int m, n, k, J[1003][1003], O[1003][1003], I[1003][1003];
string s[1003];
int main() {
	scanf("%d %d", &m, &n);
	scanf("%d", &k);
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			J[i + 1][j + 1] = J[i][j + 1] + J[i + 1][j] - J[i][j];
			O[i + 1][j + 1] = O[i][j + 1] + O[i + 1][j] - O[i][j];
			I[i + 1][j + 1] = I[i][j + 1] + I[i + 1][j] - I[i][j];
			if (s[i][j] == 'J') {
				J[i + 1][j + 1]++;
			} else if (s[i][j] == 'O') {
				O[i + 1][j + 1]++;
			} else {
				I[i + 1][j + 1]++;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d %d %d\n", J[c][d] + J[a - 1][b - 1] - J[a - 1][d] - J[c][b - 1], O[c][d] + O[a - 1][b - 1] - O[a - 1][d] - O[c][b - 1], I[c][d] + I[a - 1][b - 1] - I[a - 1][d] - I[c][b - 1]);
	}
}
