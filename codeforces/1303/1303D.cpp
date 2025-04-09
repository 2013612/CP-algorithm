#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long T, N, M, a[100], b[100], ans, two[100];
int main() {
	scanf("%lld", &T);
	two[0] = 1;
	for (int i = 1; i < 64; i++) {
		two[i] = 2*two[i - 1];
	}
	for (int i = 0; i < T; i++) {
		scanf("%lld %lld", &N, &M);
		long long sum = 0;
		int maxi = 0;
		ans = 0;
		for (int j = 0; j < 100; j++) {
			a[j] = 0;
			b[j] = 0;
		}
		for (int j = 0; j < M; j++) {
			long long temp;
			scanf("%lld", &temp);
			sum += temp;
			int pos = lower_bound(two, two + 62, temp) - two;
			a[pos]++;
			maxi = max(maxi, pos);
		}
		if (sum < N) {
			cout << -1 << endl;
			continue;
		}
		while(true) {
			long long temp = N;
			for (int j = maxi; j >= 0; j--) {
				long long temp2 = temp / two[j];
				temp -= two[j] * min(temp2, a[j]);
				b[j] = min(temp2, a[j]);
				//printf("@ %d %lld %lld %lld %lld\n", j, temp, temp2, a[j], two[j]);
			}
			//cout << "!" << temp << endl;
			if (temp == 0) {
				break;
			} else {
				ans++;
				int pos = upper_bound(two, two + 62, temp) - two;
				for (int j = pos; j < 62; j++) {
					if (a[j] - b[j] > 0) {
						a[j]--;
						a[j - 1] += 2;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
