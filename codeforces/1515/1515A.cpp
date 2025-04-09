#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, X, ans, a[103];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &X);
		int sum = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			sum += a[j];
		}
		if (sum == X) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		int cur = 0;
		for (int j = 0; j < N; j++) {
			cur += a[j];
			if (cur == X) {
				printf("%d %d ", a[j + 1], a[j]);
				cur += a[j + 1];
				j++;
			} else {
				printf("%d ", a[j]);	
			}
		}
		printf("\n");
	}
	return 0;
}
