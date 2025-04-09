#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

const int M = 998244353;
long long N, ans;
pair<int, int> a[400006];
long long per[400006];

bool f (pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}

int main() {
	scanf("%d", &N);
	per[0] = 1;
	for (int i = 1; i <= N + 1; i++) {
		per[i] = (per[i - 1] * i) % M;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + N);
	int pos = 0;
	long long temp = 1;
	for (int i = 1; i < N; i++) {
		if (a[i].first != a[i - 1].first) {
			temp = (temp * per[i - pos]) % M;
			pos = i;
		}
		if (i == N - 1) {
			temp = (temp * per[i - pos + 1]) % M;
		}
	}
	for (int i = 1; i < N; i++) {
		if (a[i].second > a[i - 1].second) {
			break;
		} else {
			
		}
	}
	ans = temp;
	sort(a, a + N, f);
	pos = 0;
	temp = 1;
	for (int i = 1; i < N; i++) {
		if (a[i].second != a[i - 1].second) {
			temp = (temp * per[i - pos]) % M;
			pos = i;
		}
		if (i == N - 1) {
			temp = (temp * per[i - pos]) % M;
		}
	}
	ans = (ans + temp) % M;
	ans = per[N] - ans;
	ans = (ans + M) % M;
	printf("%lld\n", ans);
	return 0;
}
