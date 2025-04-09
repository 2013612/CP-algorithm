#include<iostream>
#include<algorithm>
using namespace std;

int N, a[10], b[10], per[10], A, B;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		per[i] = i + 1;
	}
	for (int j = 0; j < N; j++) {
		scanf("%d", &b[j]);
	}
	int cou = 0;
	do {
		for (int i = 0; i < N; i++) {
			if (per[i] != a[i]) {
				break;
			}
			if (i == N - 1) {
				A = cou;
			}
		}
		for (int i = 0; i < N; i++) {
			if (per[i] != b[i]) {
				break;
			}
			if (i == N - 1) {
				B = cou;
			}
		}
		cou++;
	} while (next_permutation(per, per + N));
	printf("%d\n", abs(A - B));
	return 0;
}
