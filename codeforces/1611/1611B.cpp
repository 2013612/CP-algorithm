#include<iostream>
using namespace std;

int t, a, b;
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		int ans = 0;
		if (a < b) {
			swap(a, b);
		}
		int diff = a - b;
		ans += min(diff / 2, b);
		a -= min(diff / 2, b) * 3;
		b -= min(diff / 2, b);
		ans += min(a / 2, b / 2);
		printf("%d\n", ans);
	}
	return 0;
}
