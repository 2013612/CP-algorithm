#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int dp[40005][30], V, E;
unordered_map<int, int> graph[20];
bool v[40005][30];

int dpf(int a, int b) {
	if (v[a][b]) {
		return dp[a][b];
	}
	v[a][b] = true;
	for (int i = 0; i < V; i++) {
		if ((a & (1 << i)) && graph[i].count(b) == 1) {
			dp[a][b] = min(dp[a][b], dpf(a - (1 << b), i) + graph[i][b]);
		}
	}
	return dp[a][b];
}

int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < 35000; i++){
		for (int j = 0; j < 20; j++) {
			dp[i][j] = 1e9;
		}
	}
	dp[1][0] = 0;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}
	int ans = 1e9;
	for (int i = 0; i < V; i++) {
		if (graph[i].count(0)) {
			ans = min(ans, dpf((1 << V) - 1, i) + graph[i][0]);
		}
	}
	if (ans > 1e8) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}
