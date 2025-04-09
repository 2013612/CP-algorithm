#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long N, ans, a[400006], X, d[400006], sum[400006];
int main() {
	scanf("%lld %lld", &N, &X);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		a[N + i] = a[i];
	}
	d[0] = 0;
	sum[0] = 0;
	for (int i = 1; i <= 2*N; i++) {
		d[i] = d[i - 1] + a[2*N - i];
		sum[i] = sum[i - 1] + (a[2*N - i] * (a[2*N - i] + 1))/2;
		//cout << d[i] << " " << sum[i] << endl;
	}
	long long extra = 0;
	for (int i = 2*N - 1; i >= N; i--) {
		long long k = X;
		long long temp = 0;
		int pos = lower_bound(d, d + 2 * N, k + extra) - d - 1;
		//cout << pos << endl;
		k -= d[pos] - extra;
		//cout << k << endl;
		temp += sum[pos] - sum[2*N - 1 - i];
		//cout << temp << endl;
		temp += (a[2*N - pos - 1] * (a[2*N - pos - 1] + 1) - (a[2*N - pos - 1] - k) * (a[2*N - pos - 1] - k + 1))/2;
		//cout << a[2*N - pos - 1] << endl;
		//cout << temp << endl;
		ans = max(ans, temp);
		extra += a[i];
	}
	printf("%lld\n", ans);
	return 0;
}
