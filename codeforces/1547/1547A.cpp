#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, ans;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int x1, y1, x2, y2, x3, y3;
		scanf("%d %d", &x1, &y1);
		scanf("%d %d", &x2, &y2);
		scanf("%d %d", &x3, &y3);
		ans = abs(x1 - x2) + abs(y1 - y2);
		if ((x1 == x2 && x2 == x3 && (y3 - y1) * (y3 - y2) < 0) || (y1 == y2 && y2 == y3 && (x3 - x1) * (x3 - x2) < 0)) {
			ans += 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
