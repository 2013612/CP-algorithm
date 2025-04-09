#include<iostream>
#include<algorithm>
using namespace std;

int N, M, a[200005], b[200005], ans;
int main() {
	scanf("%d %d", &N, &M);
	ans = 2e9;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &b[i]);
	}
	sort(b, b + M);
	for (int i = 0; i < N; i++) {
		int pos = lower_bound(b, b + M, a[i]) - b;
		if (pos == M) {
			ans = min(ans, abs(a[i] - b[M - 1]));
		} else if (pos == 0) {
			ans = min(ans, abs(a[i] - b[0]));
		} else {
			ans = min(ans, min(abs(a[i] - b[pos]), abs(a[i] - b[pos - 1])));
		}
	}
	printf("%d\n", ans);
	return 0;
}
