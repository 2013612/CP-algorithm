#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, a[1003], b[1003], ans;
bool even, odd;
string pos = "LDRU";

int abs(int a) {
	return a > 0? a: -a;
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i], &b[i]);
		int temp = abs(a[i]) + abs(b[i]);
		if (temp % 2 == 0) {
			even = true;
		} else {
			odd = true;
		}
		ans = max(ans, temp);
	}
	if (even && odd) {
		printf("-1");
		return 0;
	}
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		printf("1 ");
	}
	for (int i = 0; i < N; i++) {
		printf("\n");
		int temp;
		if (a[i] >= 0) {
			temp = 1;
		} else {
			temp = -1;
		}
		for (int j = 0; j < abs(a[i]); j++) {
			printf("%c", pos[1 + temp]);
		}
		if (b[i] >= 0) {
			temp = 1;
		} else {
			temp = -1;
		}
		for (int j = 0; j < abs(b[i]); j++) {
			printf("%c", pos[2 + temp]);
		}
		if (ans > abs(a[i]) + abs(b[i])) {
			for (int j = 0; j < ans - (abs(a[i]) + abs(b[i])); j += 2) {
				printf("LR");
			}
		}
	}
	return 0;
}
