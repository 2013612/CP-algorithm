#include<iostream>
#include<bitset>
using namespace std;

int R, C, ans;
bitset<10004> a[20];
int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp) {
				a[i].set(j);
			} else {
				a[i].reset(j);
			}
		}
	}
	for (int i = 0; i < (1 << R); i++) {
		for (int j = 0; j < R; j++) {
			if (i & (1 << j)) {
				a[j].flip();
			}
		}
		int sum = 0;
		for (int j = 0; j < C; j++) {
			int sumc = 0;
			for (int k = 0; k < R; k++) {
				if (a[k][j]) {
					sumc++;
				}
			}
			sum += max(sumc, R - sumc);
		}
		ans = max(ans, sum);
		for (int j = 0; j < R; j++) {
			if (i & (1 << j)) {
				a[j].flip();
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
