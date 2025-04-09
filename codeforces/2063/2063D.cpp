#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
using namespace std;
 
int n, m, k;
long long ans;
deque<long long> a, b;
priority_queue<long long> pq1, pq2;
 
void solve() {
	scanf("%d %d", &n, &m);
	
	ans = 0;
	a.clear();
	b.clear();
	pq1 = priority_queue<long long>();
	pq2 = priority_queue<long long>();
	
	for (int i = 0; i < n; i++) {
		long long x;
		scanf("%lld", &x);
		a.push_back(x);
	}
	
	sort(a.begin(), a.end());
	
	for (int i = 0; i < m; i++) {
		long long x;
		scanf("%lld", &x);
		b.push_back(x);
	}
	sort(b.begin(), b.end());
	
	if (n > m) {
		swap(a, b);
		swap(n, m);
	}
	
	if (n * 2 < m) {
		k = n;
	} else {
		k = (n + m) / 3;
	}
	
	printf("%d\n", k);
	
	for (int i = 1; i <= k; i++) {
		if (a.size() >= pq2.size() + 2) {
			if (b.size() >= pq1.size() + 2) {
				if (a.back() - a.front() > b.back() - b.front()) {
					ans += a.back() - a.front();
					pq1.push(a.front() - a.back());
					a.pop_back();
					a.pop_front();
				} else {
					ans += b.back() - b.front();
					pq2.push(b.front() - b.back());
					b.pop_back();
					b.pop_front();
				}
			} else if (b.size() == pq1.size() + 1) {
				ans += a.back() - a.front();
				pq1.push(a.front() - a.back());
				a.pop_back();
				a.pop_front();
			} else {
				ans += pq2.top();
				pq2.pop();
				
				ans += a.back() - a.front();
				pq1.push(a.front() - a.back());
				a.pop_back();
				a.pop_front();
				
				ans += a.back() - a.front();
				pq1.push(a.front() - a.back());
				a.pop_back();
				a.pop_front();
			}
		} else if (a.size() == pq2.size() + 1) {
			ans += b.back() - b.front();
			pq2.push(b.front() - b.back());
			b.pop_back();
			b.pop_front();
		} else {
			ans += pq1.top();
			pq1.pop();
			
			ans += b.back() - b.front();
			pq2.push(b.front() - b.back());
			b.pop_back();
			b.pop_front();
			
			ans += b.back() - b.front();
			pq2.push(b.front() - b.back());
			b.pop_back();
			b.pop_front();
		}
		
		printf("%lld ", ans);
	}
	
	printf("\n");
}
 
int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}