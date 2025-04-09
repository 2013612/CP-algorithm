#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, X;
int main() {
	scanf("%d %d", &N, &X);
	X *= 100;
	for (int i = 1; i <= N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (X < 0) {
			continue;
		}
		X -= a * b;
		if (X < 0) {
			printf("%d\n", i);
		}
	}
	if (X >= 0) {
		printf("-1\n");
	}
	return 0;
}
