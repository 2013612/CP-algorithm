#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, T, ans, a[2004];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		for (int j = 0; j < N; j++) {
			if (j % 2 == 0) {
				a[j] = abs(a[j]);
			} else {
				a[j] = -abs(a[j]);
			}
		}
		for (int j = 0; j < N; j++) {
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	//printf("%d\n", ans);
	return 0;
} 
