#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T;
char a[1000][1000];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, M, X, Y;
		scanf("%d %d %d %d", &N, &M, &X, &Y);
		int count = 0;
		int ans = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> a[j][k];
				if (a[j][k] == '.') {
					count++;
				}
			}
		}
		if (Y >= 2*X) {
			ans = count * X;
		} else {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (a[j][k] == '.') {
						if (k != M - 1 && a[j][k + 1] == '.') {
							ans += Y;
							k++;
						} else {
							ans += X;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
