#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int Q;
long long sum;
priority_queue<long long, vector<long long>, greater<long long>> pq;
int main() {
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			pq.push(x - sum);
		} else if (t == 2) {
			int x;
			scanf("%d", &x);
			sum += x;
		} else {
			printf("%lld\n", pq.top() + sum);
			pq.pop();
		}
	}
	return 0;
}
