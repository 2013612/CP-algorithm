#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int a[300006];
long long N, K, ans;
const int M = 998244353;
bool exist = false;
int main(){
	scanf("%d %d", &N, &K);
	ans = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] == -1) {
			exist = true;
		}
	}
	if (!exist) {
		if (N == 2) {
			printf("1\n");
		} else {
			for (int i = 0; i < N - 2; i++) {
				if (a[i] == a[i + 2]) {
					printf("0\n");
					break;
				}
				if (i == N - 3) {
					printf("1\n");
				}
			}
		}
		return 0;
	}
	if (N == 2) {
		for (int i = 0; i < N; i++) {
			if (a[i] == -1) {
				ans *= K;
			}
		}
		printf("%d\n", ans);
		return 0;
	}
	if (N == 3) {
		if (a[0] == -1) {
			if (a[2] == -1) {
				ans = (ans * K) % M;
			} else {
				ans = (ans * (K - 1)) % M;
			}
		}
		if (a[1] == -1) {
			ans = (ans * K) % M;
		}
		if (a[2] == -1) {
			ans = (ans * (K - 1)) % M;
		}
		printf("%d\n", ans);
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (a[i] != -1) continue;
		if (i <= 1) {
			if (a[i + 2] == -1) {
				ans = (ans * K) % M;
			} else {
				ans = (ans * (K - 1)) % M;
			}
		} else if (i >= N - 2) {
			ans = (ans * (K - 1)) % M;
		} else {
			if (a[i + 2] == -1) {
				ans = (ans * (K - 1)) % M;
			} else {
				ans = (ans * (K - 2)) % M;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
