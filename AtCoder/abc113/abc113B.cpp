#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, T, A, a[10005], ans;

int abs (int x) {
	return x > 0? x: -x;
}

int main(){
	scanf("%d %d %d", &N, &T, &A);
	A = A * 1000;
	T = T * 1000;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	ans = 0;
	for (int i = 0; i < N; i++) {
		if (abs(A - (T - a[i] * 6)) < abs(A - (T - a[ans] * 6))) {
			ans = i;
		}
	}
	printf("%d\n", ans + 1);
}
