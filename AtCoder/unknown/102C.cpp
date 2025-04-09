#include<iostream>
using namespace std;

int N, K, A, B;
int main(){
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		if (i % K == 0) {
			A++;
		}
		if (K % 2 == 0 && i % K == K/2) {
			B++;
		}
	}
	printf("%lld\n", 1ll*A*A*A + 1ll*B*B*B);
	return 0;
}
