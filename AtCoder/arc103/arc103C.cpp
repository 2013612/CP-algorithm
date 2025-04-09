#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, a[100006], b[100006], ans, A[2][2], B[2][2];
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N / 2; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp]++;
		scanf("%d", &temp);
		b[temp]++;
	}
	for (int i = 1; i < 100003; i++) {
		if (a[i] > A[0][0]) {
			A[1][0] = A[0][0];
			A[1][1] = A[0][1];
			A[0][0] = a[i];
			A[0][1] = i;
		} else if (a[i] > A[1][0]) {
			A[1][0] = a[i];
			A[1][1] = i;
		}
	}
	for (int i = 1; i < 100003; i++) {
		if (b[i] > B[0][0]) {
			B[1][0] = B[0][0];
			B[1][1] = B[0][1];
			B[0][0] = b[i];
			B[0][1] = i;
		} else if (b[i] > B[1][0]) {
			B[1][0] = b[i];
			B[1][1] = i;
		}
	}
	if (A[0][1] == B[0][1]) {
		ans = max(A[0][0] + B[1][0], A[1][0] + B[0][0]);
	} else {
		ans = A[0][0] + B[0][0];
	}
	printf("%d\n", N - ans);
	return 0;
}
