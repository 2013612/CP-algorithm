#include<iostream>
#include<vector>
using namespace std;

int N, M, pre[30][100006], dp[2000007];
vector<int> a[30];

int solve (int now) {
	if (dp[now] != -1) {
		return dp[now];
	}
	int mini = 1e9;
	int len = 0;
	vector<int> has;
	for (int i = 1; i <= M; i++) {
		if (now & (1 << (i - 1))) {
			has.push_back(i);
			len += a[i].size();
		}
	}
	for (auto x:has) {
		mini = min(mini, solve(now - (1 << (x - 1))) + pre[x][len] - pre[x][len - a[x].size()]);
	}
	dp[now] = mini;
	return mini;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp].push_back(i);
		for (int j = 1; j <= M; j++) {
			pre[j][i] = pre[j][i - 1] + (temp != j);
		}
	}
	for (int i = 1; i <= 2000000; i++) {
		dp[i] = -1;
	}
	printf("%d\n", solve((1 << M) - 1));
	return 0;
}
