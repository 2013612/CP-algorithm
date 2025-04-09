#include<iostream>
#include<queue>
using namespace std;

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long ans = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	priority_queue<int> pq;
	
	long long sum = 0;
	
	for (int i = n - k - 1; i >= 0; i--) {
		pq.push(-a[i]);
		sum += a[i];
		
		if (pq.size() * (k + 1) > n - i) {
			sum += pq.top();
			pq.pop();
		}
		
		ans = max(ans, sum);
	}
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}