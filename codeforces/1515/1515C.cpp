#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> p;

int T, M, N, X, a[100006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &M, &X);
		priority_queue<p, vector<p>, greater<p>> pq;
		vector<int> ans(N + 1, 0);
		for (int j = 1; j <= M; j++) {
			pq.push(make_pair(0, j));
		}
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a[j]);
			p temp = pq.top();
			pq.pop();
			temp.first += a[j];
			ans[j] = temp.second;
			pq.push(temp);
		}
		printf("YES\n");
		for (int j = 1; j <= N; j++) {
			printf("%d ", ans[j]);
		}
		printf("\n");
	}
	return 0;
}
