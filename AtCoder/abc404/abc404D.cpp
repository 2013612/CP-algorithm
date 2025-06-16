#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

int n, m, c[10];
vector<int> v[10];
priority_queue<pair<long long, string>, vector<pair<long long, string>>, greater<pair<long long, string>>> pq;
unordered_map<string, long long> um;

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int t;
			scanf("%d", &t);
			t--;
			v[t].push_back(i);
		}
	}
	
	string e(m, '2');
	pq.push({0, string(m, '0')});
	while (!um.count(e) && !pq.empty()) {
		auto [x, s] = pq.top();
		pq.pop();
		
		if (um.count(s)) {
			continue;
		}
		
		um[s] = x;
		
		for (int i = 0; i < n; i++) {
			string t = s;
			for (int j = 0; j < v[i].size(); j++) {
				if (t[v[i][j]] < '2') {
					t[v[i][j]]++;
				}
			}
			
			if (!um.count(t)) {
				pq.push({x + c[i], t});
			}
		}
	}
	
	printf("%lld\n", um[e]);
	return 0;
}