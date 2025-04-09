#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	return b == 0? a : gcd(b, a % b);
}

long long N;
vector<long long> ans;
long long prod;
int main() {
	scanf("%lld", &N);
	prod = 1;
	if (N == 2) {
		printf("1\n");
		printf("1\n");
		return 0;
	}
	for (long long i = 1; i < N; i++) {
		if (gcd(i, N) == 1) {
			prod = (prod * i) % N;
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	//cout << prod << endl;
	if (prod == N - 1) {
		ans.pop_back();
	}
	printf("%d\n", ans.size());
	for (auto x:ans) {
		printf("%lld ", x);
	}
	printf("\n");
	return 0;
}
