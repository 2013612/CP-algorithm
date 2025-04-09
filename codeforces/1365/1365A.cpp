#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, M, a[103][103], b[100006][2];
string ans[2];
int main() {
	scanf("%d", &T);
	ans[0] = "Vivek";
	ans[1] = "Ashish";
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		int C = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &a[j][k]);
				if (a[j][k] == 1) {
					b[C][0] = j;
					b[C][1] = k;
					C++;
				}
			}
		}
		for (int l = 0; l < C; l++) {
			for (int k = 0; k < M; k++) {
				a[b[l][0]][k] = 1;
			}
			for (int j = 0; j < N; j++) {
				a[j][b[l][1]] = 1;
			}
		}
		/*for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				printf("%d ", a[j][k]);
			}
			cout << endl;
		}*/
		int count1 = 0;
		int count2 = 0;
		for (int j = 0; j < N; j++) {
			int sum = 0;
			for (int k = 0; k < M; k++) {
				sum += a[j][k];
			}
			count1 = max(count1, M - sum);
		}
		//printf("!%d\n", count1);
		for (int k = 0; k < M; k++) {
			int sum = 0;
			for (int j = 0; j < N; j++) {
				sum += a[j][k];
			}
			count2 = max(count2, N - sum);
		}
		//printf("@%d\n", count2);
		cout << ans[min(count1, count2) % 2] << endl;
	}
	return 0;
}
