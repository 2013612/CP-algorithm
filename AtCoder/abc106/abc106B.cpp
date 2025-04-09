#include<iostream>
using namespace std;

int N, ans;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int cou = 0;
		if (i % 2 == 0) {
			continue;
		}
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				cou++;
			}
		}
		if (cou == 8) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
