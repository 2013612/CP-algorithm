#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[32], ans, temp;

int gcd(int a, int b) {
	return a == 0? b : gcd(b % a, a);
}

int main(){
	scanf("%d", &N);
	a[0] = 1;
	for (int i = 1; i < 30; i++) {
		a[i] = 2 * a[i - 1];
	}
	if (N == 1) {
		printf("1\n");
	} else if (N == 2){
		printf("1 2\n");
	} else if (N == 3) {
		printf("1 1 3\n");
	} else {
		int L = N;
		while (L > 1) {
			for (int i = 0; i < (L + 1)/2; i++) {
				printf("%d ", a[temp]);
			}
			temp++;
			L -= (L + 1)/2;
		}
		for (int i = N; i > 0; i--) {
			if (i % a[temp - 1] == 0) {
				printf("%d", i);
				break;
			}
		}
	}
	return 0;
}
