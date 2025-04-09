#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int T, N, a[100006], ans;

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + N);
		ans = min(N - 2, a[N - 2] - 1);
		ans = max(ans, 0);
		printf("%d\n", ans);
	}

	return 0;
}
