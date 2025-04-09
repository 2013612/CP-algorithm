#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, K, ans;
int main(){
	scanf("%d %d", &N, &K);
	ans += 2 * N / K;
	ans += 5 * N / K;
	ans += 8 * N / K;
	if (2*N % K != 0) {
		ans += 1;
	}
	if (5*N % K != 0) {
		ans += 1;
	}
	if (8*N % K != 0) {
		ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}
