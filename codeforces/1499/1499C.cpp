#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long T, N, c[100006];
long long ans;
int main() {
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld", &N);
		for (int j = 0; j < N; j++) {
			scanf("%lld", &c[j]);
		}
		long long mini = 2e9;
		long long sum_e = c[0];
		long long sum_o = c[1];
		long long mini_e = c[0];
		long long mini_o = c[1];
		int cou_e = 1;
		int cou_o = 1;
		ans = c[0] * N + c[1] * N;
		bool even = true;
		for (int j = 2; j < N; j++) {
			if (even) {
				sum_e += c[j];
				mini_e = min(mini_e, c[j]);
				cou_e++;
				ans = min(ans, sum_e + mini_e * (N - cou_e) + sum_o + mini_o * (N - cou_o));
			} else {
				sum_o += c[j];
				mini_o = min(mini_o, c[j]);
				cou_o++;
				ans = min(ans, sum_e + mini_e * (N - cou_e) + sum_o + mini_o * (N - cou_o));
			}
			even = !even;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
