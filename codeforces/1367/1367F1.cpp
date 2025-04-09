#include<iostream>
#include<algorithm>
using namespace std;

int T, N, a[100006], b[100006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			b[j] = a[j];
		}
		sort(b, b + N);
		int len = 1;
		for (int j = 0; j < N; j++) {
			int ind = lower_bound(b, b + N, a[j]) - b;
			int cou = 0;
			for (int k = j; k < N; k++) {
				if (ind >= N) break;
				if (a[k] == b[ind]) {
					cou++;
					ind++;
				}
			}
			len = max(len, cou);
		}
		printf("%d\n", N - len);
	}
	return 0;
}
