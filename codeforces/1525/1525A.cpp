#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	return b == 0? a : gcd(b, a % b);
}

int T, N;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%d\n", 100 / gcd(N, 100));
	}
	return 0;
}
