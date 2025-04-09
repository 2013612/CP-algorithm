#include<iostream>
using namespace std;

long long T, N, M, Q, ans, q[100006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &M, &Q);
		ans = 0;
		for (int i = 0; i < 100006; i++) {
			q[i] = 0;
		}
		for (int k = 0; k < M; k++) {
			int temp;
			scanf("%d", &temp);
			for (int j = 1; j * j <= temp; j++) {
				if (temp % j == 0) {
					if (temp == j * j) {
						q[j] -= 1;
					} else {
						q[j] -= 1;
						q[temp/j] -= 1;
					}
				}
			}
		}
		for (int k = 0; k < Q; k++) {
			int temp;
			scanf("%d", &temp);
			ans += N/temp;
			ans += q[temp];
		}
		printf("Case #%d: %lld\n", i + 1, ans);
	}
	return 0;
}
