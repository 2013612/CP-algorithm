#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<long long, long long> pll;

long long N, ans[200006], K;
pll a[200006];
int main() {
	scanf("%lld %lld", &N, &K);
	for (int i = 1; i <= N; i++) {
		long long temp;
		scanf("%lld", &temp);
		a[i] = make_pair(temp, i);
	}
	sort(a + 1, a + 1 + N);
	for (int i = 1; i <= K % N; i++) {
		ans[a[i].second]++;
	}
	for (int i = 1; i <= N; i++) {
		printf("%lld\n", K / N + ans[i]);
	}
	return 0;
}
