#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, X, a[100006], ans;

int abs(int x) {
	return x >= 0? x: -x;
}

int gcd(int a, int b) {
	return a == 0? b: gcd(b % a, a);
}

int main(){
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		a[i] = abs(a[i] - X);
	}
	for (int i = 0; i < N; i++) {
		ans = gcd(ans, a[i]);
	}
	printf("%d\n", ans);
	return 0;
}
