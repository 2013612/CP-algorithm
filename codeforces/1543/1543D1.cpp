#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

int T;

int x(int a, int b, int k) {
	int result = 0;
	int pow = 1;
	while (a != 0 || b != 0) {
		int mod = (a % k + b % k) % k;
		result += mod * pow;
		pow *= k;
		a /= k;
		b /= k;
	}
	return result;
}

int inv(int a, int k) {
	int result = 0;
	int pow = 1;
	while (a != 0) {
		int mod = a % k;
		result += (k - mod) * pow;
		pow *= k;
		a /= k;
	}
	return result;
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, k;
		scanf("%d %d", &N, &k);
		int r = -1;
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				printf("%d\n", 0);
			} else {
				printf("%d\n", x(j, inv(j - 1, k), k));	
			}
			fflush(stdout);
			scanf("%d", &r);
			if (r == 1) {
				break;
			}
		}
	}
	return 0;
}
