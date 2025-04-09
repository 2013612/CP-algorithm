#include<iostream>
using namespace std;

int N, T, a[100006], maxi[100006];
int main() {
	scanf("%d %d", &N, &T);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int r = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			sum -= a[i - 1];
			sum = max(0, sum);
		}
		for (int j = max(r, i); j < N; j++) {
			if (sum + a[j] > T) {
				r = j;
				break;
			} else {
				sum += a[j];
			}
			if (j == N - 1) {
				r = N;
			}
		}
		maxi[i] = r - i;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, maxi[i]);
		//cout << i << " " << maxi[i] << endl;
	}
	printf("%d\n", ans);
	return 0;
}
