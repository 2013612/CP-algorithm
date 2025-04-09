#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int N, M;
long long ans;
pipii mini = {2e9, {0, 0}};
unordered_map<int, unordered_map<int, int>> edges;
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
set<int> has;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (b < a) {
			int temp = a;
			a = b;
			b = temp;
		}
		c = max(c, 0);
		if (edges[a].count(b) == 1) {
			if (edges[a][b] >= c) {
				ans += edges[a][b];
				edges[a][b] = c;
			} else {
				ans += c;
			}
		} else {
			edges[a][b] = c;
		}
		edges[b][a] = edges[a][b];
		
		if (c < mini.first) {
			mini = {c, {a, b}};
		}
	}
	has.insert(mini.second.first);
	has.insert(mini.second.second);
	edges[mini.second.first].erase(mini.second.second);
	edges[mini.second.second].erase(mini.second.first);
	for (auto x:edges[mini.second.first]) {
		pq.push({x.second, {mini.second.first, x.first}});
		if (x.first != mini.second.first) {
			edges[x.first].erase(mini.second.first);
		}
	}
	for (auto x:edges[mini.second.second]) {
		pq.push({x.second, {mini.second.second, x.first}});
		if (x.first != mini.second.second) {
			edges[x.first].erase(mini.second.second);
		}
	}
	while (!pq.empty()) {
		pipii a = pq.top();
		pq.pop();
		if (a.first > 0) {
			if (has.count(a.second.first) == 1 && has.count(a.second.second) == 1) {
				ans += a.first;
				continue;
			}
		}
		if (has.count(a.second.first) == 0) {
			has.insert(a.second.first);
			for (auto x:edges[a.second.first]) {
				pq.push({x.second, {a.second.first, x.first}});
				if (x.first != a.second.first) {
					edges[x.first].erase(a.second.first);
				}
			}
		}
		if (has.count(a.second.second) == 0) {
			has.insert(a.second.second);
			for (auto x:edges[a.second.second]) {
				pq.push({x.second, {a.second.second, x.first}});
				if (x.first != a.second.second) {
					edges[x.first].erase(a.second.second);
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
