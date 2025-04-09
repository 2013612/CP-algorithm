#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, ans, a[103];
int main() {
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		ans = a[0];
		for (int i = 0; i < N; i++) {
			ans = (ans & a[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
