#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int N, M, X, Y;
long long dis[100006];
bool arrive[100006];
vector<vector<pair<int, pair<int, int>>>> graph;
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;

void dijk(pair<int, int> x) {
	arrive[x.second] = true;
	for (auto edge:graph[x.second]) {
		long long tra = ((edge.second.second - dis[x.second]) % edge.second.second + edge.second.second) % edge.second.second + edge.second.first;
		dis[edge.first] = min(dis[edge.first], dis[x.second] + tra);
		if (!arrive[edge.first]) {
			pq.push(make_pair(tra, make_pair(x.second, edge.first)));
		}
	}
	while(!pq.empty() && arrive[pq.top().second.second]) {
		pq.pop();
	}
	if (!pq.empty()) {
		pair<int, int> next = pq.top().second;
		pq.pop();
		dijk(next);
	}
}

int main() {
	scanf("%d %d %d %d", &N, &M, &X, &Y);
	for (int i = 0; i <= N; i++) {
		vector<pair<int, pair<int, int>>> temp;
		graph.push_back(temp);
		dis[i] = 1e18;
	}
	for (int i = 0; i < M; i++) {
		int a, b, t, k;
		scanf("%d %d %d %d", &a, &b, &t, &k);
		graph[a].push_back(make_pair(b, make_pair(t, k)));
		graph[b].push_back(make_pair(a, make_pair(t, k)));
	}
	dis[X] = 0;
	arrive[X] = true;
	for (auto edge:graph[X]) {
		dis[edge.first] = edge.second.first;
		pq.push(make_pair(edge.second.first, make_pair(X, edge.first)));
	}
	if (!pq.empty()) {
		pair<int, int> start = pq.top().second;
		pq.pop();
		dijk(start);
	}
	
	if (!arrive[Y]) {
		printf("-1\n");
	} else {
		printf("%lld\n", dis[Y]);
	}
	return 0;
}
