#include<iostream>
using namespace std;

int T, R, G, B;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &R, &G, &B);
		int ans = 2e9;
		if ((R - G) % 3 == 0) {
			ans = min(ans, max(R, G));
		}
		if ((R - B) % 3 == 0) {
			ans = min(ans, max(R, B));
		}
		if ((B - G) % 3 == 0) {
			ans = min(ans, max(B, G));
		}
		if (ans > 1e9) {
			ans = -1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
