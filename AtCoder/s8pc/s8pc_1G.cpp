#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef pair<long long, long long> pll;

long long V, E;
unordered_map<int, pll> graph[20], dp[100006];
bool v[100006][30];

pll dpf(int a, int b) {
	if (v[a][b]) {
		return dp[a][b];
	}
	v[a][b] = true;
	for (int i = 0; i < V; i++) {
		if ((a & (1 << i)) && graph[i].count(b) == 1) {
			pll temp = dpf(a - (1 << b), i);
			long long temp2 = temp.first + graph[i][b].first;
			if (temp2 <= graph[i][b].second) {
				if (temp2 < dp[a][b].first) {
					dp[a][b] = {temp2, temp.second};
				} else if (temp2 == dp[a][b].first) {
					dp[a][b].second += temp.second;
				}
			}
		}
	}
	return dp[a][b];
}

int main() {
	scanf("%lld %lld", &V, &E);
	for (int i = 0; i < 70000; i++){
		for (int j = 0; j < 20; j++) {
			dp[i][j] = {1e16, 0};
		}
	}
	dp[1][0] = {0, 1};
	for (int i = 0; i < E; i++) {
		long long a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		graph[a - 1][b - 1] = {c, d};
		graph[b - 1][a - 1] = {c, d};
	}
	if (V == 1) {
		printf("0 1\n");
		return 0;
	}
	long long ans = 1e16;
	long long cnt = 0;
	for (int i = 0; i < V; i++) {
		if (graph[i].count(0)) {
			pll temp = dpf((1 << V) - 1, i);
			if (temp.first + graph[i][0].first <= graph[i][0].second) {
				if (temp.first + graph[i][0].first < ans) {
					ans = temp.first + graph[i][0].first;
					cnt = temp.second;
				} else if (temp.first + graph[i][0].first == ans) {
					cnt += temp.second;
				}
			}
		}
	}
	if (cnt == 0) {
		printf("IMPOSSIBLE\n");
	} else {
		printf("%lld %lld\n", ans, cnt);
	}
	return 0;
}
