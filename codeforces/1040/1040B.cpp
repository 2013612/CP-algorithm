#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, K;
int main(){
	scanf("%d %d", &N, &K);
	if (N <= 2*K + 1) {
		printf("1\n");
		printf("%d\n", (N + 1)/2);
	} else {
		if (N % (2*K + 1) == 0) {
			printf("%d\n", N/(2*K + 1));
			for (int i = 0; i < N/(2*K + 1); i++) {
				printf("%d ", K + 1 + i*(2*K + 1));
			}
			printf("\n");
		} else {
			printf("%d\n", N/(2*K + 1) + 1);
			int remainder = N % (2*K + 1);
			int initial;
			if (remainder >= K + 1) {
				initial = K + 1 - (2*K + 1) + remainder;
			} else {
				initial = 1;
			}
			for (int i = 0; i < N/(2*K + 1) + 1; i++) {
				printf("%d ", initial);
				initial += (2*K + 1);
			}
			printf("\n");
		}
	}
	return 0;
}
