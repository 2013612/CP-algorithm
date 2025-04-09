#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[300006], ans, GCD, b[15000008], fac[15000008];

int gcd(int a, int b) {
	return a == 0? b : gcd(b % a, a);
}

void outputprime(int n){ // vector is used
	int temp;
	for (int i = 2; i*i <= n; i++) {
		if (b[i] > 0){
			continue;
		} else {
			for (int j = i; j <= n; j+=i){
				b[j] = i;
			}
		}
		temp = i;
	}
	for (int i = temp + 1; i < n; i++) {
		if (b[i] == 0) {
			b[i] = i;
		}
	}
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		GCD = gcd(GCD, a[i]);
	}
	for (int i = 1; i < N; i++) {
		if (a[i] != a[i - 1]) {
			break;
		}
		if (i == N - 1) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 0; i < N; i++) {
		a[i] /= GCD;
	}
	outputprime(15000000);
	for (int i = 0; i < N; i++) {
		while (a[i] > 1) {
			int temp = b[a[i]];
			fac[temp]++;
			ans = max(ans, fac[temp]);
			while (a[i] % temp == 0) {
				a[i] /= temp;
			}
		}
	}
	printf("%d\n", N - ans);
	return 0;
}
