#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int T, N, X, ans, a[100006];
int main() {
	scanf("%d", &T);
	for (int j = 0; j < T; j++) {
		scanf("%d %d", &N, &X);
		int sum = 0;
		ans = -1;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int temp = sum;
		//printf("!%d\n", temp);
		for (int i = 0; i < N; i++) {
			if (temp % X != 0) {
				ans = N - i;
				break;
			} else {
				temp -= a[i];
			}
		}
		//printf("@%d\n", temp);
		temp = sum;
		for (int i = N - 1; i >= 0; i--) {
			if (temp % X != 0) {
				ans = max(ans, i + 1);
				break;
			} else {
				temp -= a[i];
			}
		}
		//printf("#%d\n", temp);
		printf("%d\n", ans);
	}
	return 0;
}
