#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans[300006], s[300006];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int pos = i;
		int val = abs(s[i] - s[i + 1]);
		if (s[i + 1] > s[i]) {
			pos = i + 3;
		}
		ans[pos] += val;
		for (int j = max(pos - 2, 0); j <= pos; j++) {
			s[j] -= val;
		}
		for (int i = 0; i < n; i++) {
			printf("%d ", s[i]);
		}
		printf("\n");
		for (int i = 0; i < n + 2; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i += 3) {
		ans[i + 2] += s[i];
	}
	for (int i = 0; i < n + 2; i++) {
		if (ans[i] < 0) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 0; i < n + 2; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
