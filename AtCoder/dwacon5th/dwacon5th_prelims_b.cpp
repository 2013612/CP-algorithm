#include<iostream>
#include<unordered_map>
using namespace std;

int n, k, a[1004];
unordered_map<long long, int> um;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	long long maxi = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		long long sum = 0;
		for (int j = i; j < n; j++) {
			sum = sum + a[j];
			um[sum]++;
			maxi = max(maxi, sum);
		}
	}
	for (long long i = 0; maxi > 0; i++) {
		maxi /= 2;
		if (maxi == 0) {
			maxi = (1ll << i);
			break;
		}
	}
	while (maxi > 0) {
		int cnt = 0;
		unordered_map<long long, int> temp;
		for (auto x:um) {
			if ((x.first & maxi) == maxi) {
				temp[x.first] = x.second;
				cnt += x.second;
			}
		}
		if (cnt >= k) {
			um = temp;
			ans += maxi;
		}
		maxi >>= 1;
	}
	printf("%lld\n", ans);
	return 0;
}
