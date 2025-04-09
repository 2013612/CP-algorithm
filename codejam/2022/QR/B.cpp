#include<iostream>
using namespace std;

int t;

const int SUM = 1e6;

void solve(int case_num) {
	int c[4];
	c[0] = c[1] = c[2] = c[3] = 1e9;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			int p;
			scanf("%d", &p);
			c[j] = min(c[j], p);
		}
	}
	int temp = SUM;
	int ans[4];
	for (int i = 0; i < 4; i++) {
		ans[i] = min(c[i], temp);
		temp -= min(c[i], temp);
	}
	printf("Case #%d: ", case_num);
	if (temp > 0) {
		printf("IMPOSSIBLE\n");
	} else {
		for (int i = 0; i < 4; i++) {
			printf("%d%c", ans[i], i == 3 ? '\n' : ' ');
		}
	}
}

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
	return 0;
}
