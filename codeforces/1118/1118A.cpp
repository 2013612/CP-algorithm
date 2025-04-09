#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long T, N, A, B, ans;
int main(){
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld %lld %lld", &N, &A, &B);
		if (N % 2 == 0) {
			printf("%lld\n", min(A*N, B*(N/2)));
		} else {
			printf("%lld\n", min(A*N, B*(N/2) + A));
		}
	}
	return 0;
}
