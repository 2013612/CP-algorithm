#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long N, ans, x[303], y[303];
int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				long long temp1 = (x[j] - x[i]) * (y[k] - y[j]);
				long long temp2 = (x[k] - x[j]) * (y[j] - y[i]);
				if (temp1 != temp2) {
					ans++;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
