#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, a[200006], b[200006];
long long ans;
priority_queue<pair<long long, int>> pq;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = 1;
		pq.push({-3ll * a[i], i});
	}
	
	for (int i = 0; i < n - 2; i++) {
		auto x = pq.top();
		pq.pop();
		b[x.second]++;
		pq.push({-1ll * (2 * b[x.second] + 1) * a[x.second], x.second});
	}
	
	for (int i = 0; i < n; i++) {
		ans += 1ll * b[i] * b[i] * a[i];
	}
	
	printf("%lld\n", ans);
	return 0;
}