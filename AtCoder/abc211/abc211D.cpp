#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int Q = 1e9 + 7;
int N, M;
long long dis[200006], num[200006];
vector<int> edge[200006];
queue<int> q;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < 200005; i++) {
		dis[i] = -1;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (auto x:edge[1]) {
		q.push(x);
		dis[x] = 1;
		num[x] = 1;
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto x:edge[node]) {
			if (dis[x] == -1) {
				dis[x] = dis[node] + 1;
				q.push(x);
			}
			if (dis[x] == dis[node] + 1) {
				num[x] += num[node];
			}
			num[x] %= Q;
		}
	}
	printf("%lld\n", num[N]);
	return 0;
}
