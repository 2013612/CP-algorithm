#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;

int T, a[300006], t[300006], ans[300006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, K;
		scanf("%d %d", &N, &K);
		for (int j = 1; j <= K; j++) {
			scanf("%d", &a[j]);
		}
		for (int j = 1; j <= K; j++) {
			scanf("%d", &t[j]);
		}
		for (int j = 1; j <= N; j++) {
			ans[j] = 2e9;
		}
		priority_queue<pii, vector<pii>, greater<pii>> q;
		for (int j = 1; j <= K; j++) {
			q.push({t[j], a[j]});
		}
		while (!q.empty()) {
			pii temp = q.top();
			q.pop();
			if (temp.second < 1 || temp.second > N) {
				continue;
			}
			if (temp.first < ans[temp.second]) {
				ans[temp.second] = temp.first;
				q.push({temp.first + 1, temp.second + 1});
				q.push({temp.first + 1, temp.second - 1});
			}
		}
		for (int j = 1; j <= N; j++) {
			printf("%d ", ans[j]);
		}
		printf("\n");
	}
	return 0;
}
