#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<tuple>
using namespace std;

int n, m;
long long a[200006], b[200006], c[200006], ans;
priority_queue<pair<long long, vector<int>>> pq;
set<tuple<int, int, int>> s;

long long mul(int i, int j, int k) {
	return a[i] * b[j] + b[j] * c[k] + a[i] * c[k];
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &c[i]);
	}
	
	sort(a, a + n, greater<long long>());
	sort(b, b + n, greater<long long>());
	sort(c, c + n, greater<long long>());
	
	pq.push({mul(0, 0, 0), {0, 0, 0}});
	s.insert({0, 0, 0});
	
	while (m-- > 1) {
		auto x = pq.top().second;
		
		pq.pop();
		
		for (int i = 0; i < 3; i++) {
			auto k = x;
			k[i] = x[i] + 1;
			tuple<int, int, int> k2 = {k[0], k[1], k[2]};
			
			if (k[i] >= n || s.count(k2)) {
				continue;
			}
			
			s.insert(k2);
			pq.push({mul(k[0], k[1], k[2]), k});
		}
	}
	
	printf("%lld\n", pq.top().first);
	
	return 0;
}