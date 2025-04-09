#include<iostream>
#include<atcoder/scc>
#include<set>
using namespace std;
using namespace atcoder;

int n;
string s, t;
set<int> adj[26];

int main() {
	scanf("%d", &n);
	cin >> s >> t;
	
	if (s == t) {
		printf("0\n");
		return 0;
	}
	
	if ((set(t.begin(), t.end())).size() == 26) {
		printf("-1\n");
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		adj[s[i] - 'a'].insert(t[i] - 'a');
	}
	
	for (int i = 0; i < 26; i++) {
		if (adj[i].size() > 1) {
			printf("-1\n");
			return 0;
		}
		
		adj[i].erase(i);
	}
	
	scc_graph g(26);
	
	for (int i = 0; i < 26; i++) {
		for (auto v: adj[i]) {
			g.add_edge(i, v);
		}
	}
	
	auto scc = g.scc();
	int ans = 0;
	
	for (auto arr: scc) {
		if (arr.size() == 1) {
			ans += adj[arr[0]].size() > 0;
		} else {
			bool has = false;
			set<int> k = set(arr.begin(), arr.end());
			for (int i = 0; i < 26 && !has; i++) {
				if (k.count(i)) {
					continue;
				}
				
				for (auto x: adj[i]) {
					if (k.count(x)) {
						has = true;
						break;
					}
				}
			}
			
			ans += arr.size() + !has;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}