#include<iostream>
using namespace std;

long long N, S[200006], T[200006], ans[200006];
int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &S[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%lld", &T[i]);
	}
	for (int i = 0; i < 2 * N; i++) {
		T[(i + 1) % N] = min(T[(i + 1) % N], T[i % N] + S[i % N]);
	}
	for (int i = 0; i < N; i++) {
		printf("%lld\n", T[i]);
	}
	return 0;
}
