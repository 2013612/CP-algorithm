#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

long long N, M, K, a[300006], sum[300006], ans, maxi[300006];

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			sum[i] = a[i];
		} else {
			sum[i] = sum[i - 1] + a[i];
		}
		//cout << "!" << sum[i] << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= M && i - j >= 0; j++) {
			maxi[i] = max(maxi[i], maxi[i - j] + sum[i] - sum[i - j] - K);
			//cout << i << " " << j << " " << maxi[i] << endl;
		}
		ans = max(ans, maxi[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
