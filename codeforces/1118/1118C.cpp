#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, a[2004], b[2004];
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N*N; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp]++;
		b[temp]++;
	}
	if (N % 2 == 0) {
		for (int i = 1; i <= 1000; i++) {
			if (a[i] % 4 != 0) {
				printf("NO\n");
				return 0;
			}
		}
		printf("YES\n");
		int ans[N][N];
		int cou = 1;
		for (int i = 0; i < N*N/4;) {
			if (a[cou] > 0) {
				ans[i/(N/2)][i % (N/2)] = cou;
				ans[i/(N/2)][N - 1 - i % (N/2)] = cou;
				ans[N - 1 - i/(N/2)][i % (N/2)] = cou;
				ans[N - 1 - i/(N/2)][N - 1 - i % (N/2)] = cou;
				a[cou] -= 4;
				i++;
			} else {
				cou++;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	} else {
		vector<int> one, two, four;
		for (int i = 1; i <= 1000; ) {
			if (b[i] > 0) {
				if (b[i] % 2 == 1) {
					b[i]--;
					one.push_back(i);
					continue;
				} else {
					if (b[i] >= 4 && 4*four.size() < N * N - 1 - (N - 1) * 2) {
						b[i] -= 4;
						four.push_back(i);
						continue;
					} else {
						b[i] -= 2;
						two.push_back(i);
						continue;
					}
				}
			} else {
				i++;
			}
		}
		if (one.size() != 1 || two.size() != N - 1|| 4*four.size() != N * N - 1 - (N - 1) * 2) {
			printf("NO\n");
			return 0;
		} else {
			printf("YES\n");
		}
		int ans[N][N];
		int cou = 1;
		ans[N/2][N/2] = one.back();
		for (int i = 0; i < N/2; i++) {
			ans[i][N/2] = two.back();
			ans[N - 1 - i][N/2] = two.back();
			two.pop_back();
		}
		for (int i = 0; i < N/2; i++) {
			ans[N/2][i] = two.back();
			ans[N/2][N - 1 - i] = two.back();
			two.pop_back();
		}
		for (int i = 0; i < (N/2)*(N/2); i++) {
			ans[i/(N/2)][i % (N/2)] = four.back();
			ans[i/(N/2)][N - 1 - i % (N/2)] = four.back();
			ans[N - 1 - i/(N/2)][i % (N/2)] = four.back();
			ans[N - 1 - i/(N/2)][N - 1 - i % (N/2)] = four.back();
			four.pop_back();
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
