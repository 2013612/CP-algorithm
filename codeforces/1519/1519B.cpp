#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, M, K;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &M, &K);
		if (K == M * N - 1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
