#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, ans, a[100006];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int b, c;
		scanf("%d %d", &b, &c);
		a[b]++;
		a[c]++;
	}
	for (int i = 1; i <= N; i++) {
		if (a[i] == N - 1) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
