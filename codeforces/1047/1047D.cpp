#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, ans;
int main(){
	scanf("%d %d", &N, &M);
	if (N + M <= 4) {
		printf("0\n");
		return 0;
	}
	if (N > M) {
		int temp = N;
		N = M;
		M = temp;
	}
	if (N == 1) {
		ans += M - M % 6;
		if (M % 6 == 4) {
			ans += 2;
		} else if (M % 6 == 5) {
			ans += 4;
		}
		printf("%d\n", ans);
		return 0;
	}
	if (N == 2 && (M == 3 || M == 7)) {
		printf("%d\n", N * M - 2);
		return 0;
	}
	if (((N % 2) * (M % 2)) % 2 == 0) {
		printf("%lld\n", 1ll*N*M);
	} else {
		printf("%lld\n", 1ll*N*M - 1);
	}
	return 0;
}
