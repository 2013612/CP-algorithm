#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;

int n, m;
long long ans;
dsu d(200006);
vector<int> edge[200006];
unordered_map<int, int> um;

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		d.merge(a, b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		um[d.leader(i)] += edge[i].size();
	}
	
	for (auto [x, y]: um) {
		ans += 1ll * d.size(x) * (d.size(x) - 1) - y;
	}
	
	printf("%lld\n", ans / 2);
	
	return 0;
}