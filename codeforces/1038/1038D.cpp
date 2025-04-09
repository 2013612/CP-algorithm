#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, A[1000007];
long long ans;
bool neg = true, pos = true;

int abs(int a) {
	return a >= 0? a: -a;
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	if (N == 1) {
		printf("%d\n", A[0]);
		return 0;
	}
	for (int i = 0 ; i < N; i++) {
		if (A[i] >= 0) {
			neg = false;
		}
		if (A[i] <= 0) {
			pos = false;
		}
	}
	if (neg || pos) {
		int mini = 1000000010;
		for (int i = 0; i < N; i++) {
			ans = ans + abs(A[i]);
			mini = min(mini, abs(A[i]));
		}
		ans = ans - 2*mini;
	} else {
		for (int i = 0; i < N; i++) {
			ans = ans + abs(A[i]);
		} 
	}
	printf("%lld\n", ans);
	return 0;
}

