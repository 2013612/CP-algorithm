#include<iostream>
#include<queue>
using namespace std;

int N, M, a[2000007], cur[2000007], ans;
priority_queue <int, vector<int>, greater<int> > pq;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < M; i++) {
		cur[a[i]]++;
	}
	for (int i = 0; i <= N; i++) {
		if (cur[i] == 0) {
			pq.push(i);
		}
	}
	ans = pq.top();
	for (int i = M; i < N; i++) {
		cur[a[i]]++;
		cur[a[i - M]]--;
		if (cur[a[i - M]] == 0) {
			pq.push(a[i - M]);
		}
		while(cur[pq.top()] > 0) {
			pq.pop();
		}
		ans = min(ans, pq.top());
	}
	printf("%d\n", ans);
	return 0;
}
