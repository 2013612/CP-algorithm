#include<bits/stdc++.h>
using namespace std;

long long n, m, ans;
pair<long long, long long> a[200005];

bool f(pair<long long, long long> a, pair<long long, long long> b) {
	return a.first - a.second < b.first - b.second;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%lld %lld", &a[i].first, &a[i].second);
	}
	
	sort(a, a + m, f);
	
	for (int i = 0; i < m; i++) {
//		printf("%d %d %lld\n", i, a[i].first, ans);
		if (n < a[i].first) {
			continue;
		}
		
		long long diff = a[i].first - a[i].second;
		long long num = (n - a[i].first) / diff + 1;
		
		ans += num;
		n -= num * diff;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}