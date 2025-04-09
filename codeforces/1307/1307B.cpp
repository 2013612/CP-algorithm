#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int T, N, a[100006], ans, X;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &X);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		sort(a, a + N);
		if (a[N - 1] > X) {
			if (binary_search(a, a + N, X)) {
				ans = 1;
			} else {
				ans = 2;
			}
		} else {
			int temp = X / a[N - 1] + 1;
			if (X % a[N - 1] == 0) {
				temp--;
			}
			ans = temp;
		}
		printf("%d\n", ans);
	}
	return 0;
}
