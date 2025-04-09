#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int T, N, ans, a[2004], b[2004];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		ans = -1;
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		sort(a, a + N);
		for (int j = 1; j <= 2048; j++) {
			for (int k = 0; k < N; k++) {
				b[k] = a[k] ^ j;
			}
			sort(b, b + N);
			bool success = false;
			for (int k = 0; k < N; k++) {
				if (a[k] != b[k]) {
					break;
				}
				if (k == N - 1) {
					success = true;
				}
			}
			if (success) {
				ans = j;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
