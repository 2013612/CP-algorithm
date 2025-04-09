#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, K, A[300006], B[300006], ans;
int main() {
	scanf("%d %d %d", &N, &M, &K);
	int k = K;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 0; i < N; i++) {
		if (K >= A[i]) {
			K -= A[i];
			ans++;
		} else {
			break;
		}
	}
	int pos = 0;
	/*if (ans == N) {
		for (int i = 0; i < M; i++) {
			if (K >= B[i]) {
				K -= B[i];
				ans++;
			} else {
				pos = i;
				break;
			}
			if (i == M - 1) {
				pos = i;
			}
		}
	}*/
	int cou = ans;
	for (int i = ans - 1; i >= 0; i--) {
		//printf("%d\n", ans);
		//if (pos == M - 1) {
		//	break;	
		//}
		for (int j = pos; j < M; j++) {
			if (K >= B[j]) {
				K -= B[j];
				cou++;
			} else {
				pos = j;
				break;
			}
			if (j == M - 1) {
				pos = M;
			}
		}
		ans = max(ans, cou);
		cou--;
		K += A[i];
	}
	cou = 0;
	K = k;
	for (int i = 0; i < M; i++) {
		if (K >= B[i]) {
			K -= B[i];
			cou++;
		} else {
			ans = max(ans, cou);
			break;
		}
		if (i == M - 1) {
			ans = max(ans, cou);
		}
	}
	printf("%d\n", ans);
	return 0;
}
