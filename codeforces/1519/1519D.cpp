#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long N, a[5004], b[5004], ans, init;
int main() {
	scanf("%lld", &N);
	for (int j = 0; j < N; j++) {
		scanf("%lld", &a[j]);
	}
	for (int j = 0; j < N; j++) {
		scanf("%lld", &b[j]);
	}
	for (int j = 0; j < N; j++) {
		init += a[j] * b[j];
	}
	ans = init;
	for (int i = 1; i < N - 1; i++) {
		long long temp = init;
		for (int j = 1; i - j >= 0 && i + j < N; j++) {
			//temp -= a[i - j] * b[i - j] + a[i + j] * b[i + j];
			temp += a[i - j] * (b[i + j] - b[i - j]) + a[i + j] * (b[i - j] - b[i + j]);
			ans = max(ans, temp);
		}
 	}
 	for (int left = 0, right = 1; right < N; left++, right++) {
 		long long temp = init;
 		for (int i = 0; left - i >= 0 && right + i < N; i++) {
 			temp += a[left - i] * (b[right + i] - b[left - i]) + a[right + i] * (b[left - i] - b[right + i]);
 			ans = max(ans, temp);
 		}
 	}
 	printf("%lld\n", ans);
	return 0;
}
