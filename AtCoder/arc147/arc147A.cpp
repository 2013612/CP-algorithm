#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, ans, a[200006], mini = 2e9;
priority_queue<int> pq;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mini = min(mini, a[i]);
		pq.push(a[i]);
	}
	while (pq.size() > 1) {
		int t = pq.top();
		pq.pop();
		t %= mini;
		if (t > 0) {
			mini = min(mini, t);
			pq.push(t);
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}