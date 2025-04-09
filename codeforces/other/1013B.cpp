#include<iostream>
#include<algorithm>
using namespace std;

int N, X, a[100006], b[100006];
int main(){
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N);
	for (int i = 1; i < N; i++) {
		if (a[i] == a[i - 1]) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = 0; i < N; i++) {
		b[i] = a[i] & X;
	}
	for (int i = 0; i < N; i++) {
		if (binary_search(a, a + N, b[i])) {
			int temp = lower_bound(a, a + N, b[i]) - a;
			if (temp != i) {
				printf("1\n");
				return 0;
			} else {
				if (a[temp + 1] == b[i]) {
					printf("1\n");
					return 0;
				}
			}
		}
	}
	sort(b, b + N);
	for (int i = 1; i < N; i++) {
		if (b[i] == b[i - 1]) {
			printf("2\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
