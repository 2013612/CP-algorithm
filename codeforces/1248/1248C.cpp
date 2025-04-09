#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

long long N, M, F[100006];
const int K = 1000000007;
int main() {
	scanf("%d %d", &N, &M);
	F[0] = 1;
	F[1] = 1;
	for (int i = 2; i <= 100001; i++) {
		F[i] = F[i - 2] + F[i - 1];
		F[i] = F[i] % K;
	}
	long long ans = F[N];
	for (int i = 0; i <= M - 2; i++) {
		ans += F[i];
		ans = ans % K;
	}
	ans = ans * 2;
	ans = ans % K;
	printf("%d\n", ans);
	return 0;
}
