#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int M = 998244353;
int N, ans, front, back;
char c[300006];
int main(){
	scanf("%d", &N);
	scanf("%s", c);
	front = back = 1;
	for (int i = 1; i < N; i++) {
		if (c[i] != c[i - 1]) {
			break;
		}
		front++;
		if (i == N - 1) {
			long long temp = 1ll * N * (N + 1) / 2;
			temp = temp % M;
			printf("%lld\n", temp);
			return 0;
		}
	}
	for (int i = N - 2; i >= 0; i--) {
		if (c[i] != c[i + 1]) {
			break;
		}
		back++;
	}
	ans += front;
	ans += back;
	ans = ans % M;
	if (c[0] == c[N - 1]) {
		long long temp = (1ll * front * back) % M;
		ans = (temp + ans) % M;
	}
	ans++;
	printf("%d\n", (ans + M) % M);
	return 0;
}
