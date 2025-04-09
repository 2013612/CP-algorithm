#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, a[400006], ans, K, dif[400006];

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	if (N == K) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < N - 1; i++) {
		dif[i] = a[i + 1] - a[i];
	}
	sort(dif, dif + N - 1);
	ans = a[N - 1] - a[0];
	int sum = 0;
	for (int i = N - 2; i > N - K - 1; i--) {
		sum += dif[i];
	}
	printf("%d\n", ans - sum);
	return 0;
}
