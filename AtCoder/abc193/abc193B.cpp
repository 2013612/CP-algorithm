#include<iostream>
using namespace std;

int N, ans;
int main() {
	ans = 2e9;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, p, x;
		scanf("%d %d %d", &a, &p, &x);
		if (x - a > 0) {
			ans = min(ans, p);
		}
	}
	if (ans > 1e9) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}
