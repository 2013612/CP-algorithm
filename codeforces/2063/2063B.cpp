#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, l, r, a[200006];
long long ans;

void solve() {
	scanf("%d %d %d", &n, &l, &r);
	
	l--;
	
	ans = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	{
		priority_queue<int> pq;
		for (int i = 0; i < r; i++) {
			pq.push(-a[i]);
		}
		
		for (int i = 0; i < r - l; i++) {
			ans += -pq.top();
			pq.pop();
		}
	}
	
	{
		long long p = 0;
		priority_queue<int> pq;
		for (int i = l; i < n; i++) {
			pq.push(-a[i]);
		}
		
		for (int i = 0; i < r - l; i++) {
			p += -pq.top();
			pq.pop();
		}
		
		ans = min(ans, p);
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