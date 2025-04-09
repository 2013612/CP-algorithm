#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int N, M, Start, a[100006], dist[100006];
vector<pair<int, int>> E[100006];
vector<int> topo;

void dfs_topo(int x) {
	a[x] = -1;
	for (auto y:E[x]) {
		if (a[y.first] == 0) {
			dfs_topo(y.first);
		}
	}
	a[x] = 1;
	topo.push_back(x);
}



int main() {
	scanf("%d %d %d", &N, &M, &Start);
	for (int i = 0; i < M; i++) {
		int temp, temp2, temp3;
		scanf("%d %d %d", &temp, &temp2, &temp3);
		E[temp].push_back(make_pair(temp2, temp3));
	}
	dfs_topo(Start);
	for (int i = 1; i <= N; i++) {
		if (i != Start) {
			dist[i] = 1e9;
		}
	}
	for (int i = topo.size() - 1; i >= 0; i--) {
		for (auto y:E[topo[i]]) {
			dist[y.first] = min(dist[y.first], dist[topo[i]] + y.second);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << i << " " << dist[i] << endl;
	}
	return 0;
}
