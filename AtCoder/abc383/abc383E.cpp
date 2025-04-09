#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;

int n, m, k, dsu[200006], s[2][200006], cnt;
set<int> used;
map<int, int> a, b;
priority_queue<pair<int, pair<int, int>>> pq;
long long ans;

int find(int a) {
	if (dsu[a] == a) {
		return a;
	}
	
	return dsu[a] = find(dsu[a]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);
	
	if (x == y) {
		return;
	}
	
	dsu[x] = y;
	s[0][y] += s[0][x];
	s[1][y] += s[1][x];
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	
	for (int i = 1; i <= n; i++) {
		dsu[i] = i;
	}
	
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		
		pq.push({-w, {u, v}});
	}
	
	for (int i = 0; i < k; i++) {
		int t;
		scanf("%d", &t);
		a[t]++;
	}
	
	for (int i = 0; i < k; i++) {
		int t;
		scanf("%d", &t);
		b[t]++;
	}
	
	while (cnt < n - 1) {
		auto [w, p] = pq.top();
		auto [x, y] = p;
		pq.pop();
		if (find(x) == find(y)) {
			continue;
		}
		
		cnt++;
		
		used.insert(x);
		used.insert(y);
		
		merge(x, y);
		
		int fx = find(x);
		s[0][fx] += a[x] + a[y];
		a.erase(x);
		a.erase(y);
		
		s[1][fx] += b[x] + b[y];
		b.erase(x);
		b.erase(y);
		
		int c = min(s[0][fx], s[1][fx]);
		ans += 1ll * c * -w;
		s[0][fx] -= c;
		s[1][fx] -= c;
	}
	
	printf("%lld\n", ans);
 	
	return 0;
}