#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long T, N;
int main() {
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld", &N);
		bool can = false;
		for (long long j = 1; 2 * j * j <= N; j++) {
			if (N == 2 * j * j || N == 4 * j * j) {
				printf("YES\n");
				can = true;
				break;
			}
		}
		if (!can) {
			printf("NO\n");
		}
	}
	return 0;
}
