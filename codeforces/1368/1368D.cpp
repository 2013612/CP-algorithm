#include<iostream>
using namespace std;

int N, b[30];
long long a[300006], ans, two[40];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	two[0] = 1;
	for (int i = 1; i < 30; i++) {
		two[i] = two[i - 1] * 2;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 30; j++) {
			if (a[i] & two[j]) {
				b[j]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		long long temp = 0;
		for (int j = 0; j < 30; j++) {
			if (b[j] > 0) {
				temp += two[j];
				b[j]--;
			}
		}
		ans += temp * temp;
	}
	printf("%lld\n", ans);
	return 0;
}
