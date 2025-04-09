#include<iostream>
#include<string>
using namespace std;

int T, N;
char ans[100][100];

int main() {
	freopen("travel_restrictions_input.txt", "r", stdin);
	freopen("travel_restrictions_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		string in, out;
		cin >> in >> out;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ans[j][k] = ' ';
			}
		}
		for (int j = 0; j < N; j++) {
			if (out[j] == 'N') {
				for (int k = 0; k < N; k++) {
					ans[j][k] = 'N';
				}
				ans[j][j] = 'Y';
				continue;
			}
			ans[j][j] = 'Y';
			for (int k = j - 1; k >= 0; k--) {
				if (in[k] == 'Y') {
					ans[j][k] = 'Y';
				} else {
					for (int l = k; l >= 0; l--) {
						ans[j][l] = 'N';
					}
					break;
				}
				if (out[k] == 'N') {
					for (int l = k - 1; l >= 0; l--) {
						ans[j][l] = 'N';
					}
					break;	
				}
			}
			for (int k = j + 1; k < N; k++) {
				if (in[k] == 'Y') {
					ans[j][k] = 'Y';
				} else {
					for (int l = k; l < N; l++) {
						ans[j][l] = 'N';
					}
					break;
				}
				if (out[k] == 'N') {
					for (int l = k + 1; l < N; l++) {
						ans[j][l] = 'N';
					}
					break;	
				}	
			}
		}

		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				printf("%c", ans[j][k]);
			}
			printf("\n");
		}
	}
	return 0;	
}
