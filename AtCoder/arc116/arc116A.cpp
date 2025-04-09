#include<iostream>
using namespace std;

int T;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		long long N;
		scanf("%lld", &N);
		if (N % 2 == 1) {
			printf("Odd\n");
		} else {
			if (N % 4 == 0) {
				printf("Even\n");
			} else {
				printf("Same\n");
			}
		}
	}
	return 0;
} 
