#include<iostream>
using namespace std;

int N, a[1004], b[1004], ans;
int main() {
	scanf("%d", &N);
	ans = 1e9;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				ans = min(ans, a[i] + b[j]);
			} else {
				ans = min(ans, max(a[i], b[j]));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
