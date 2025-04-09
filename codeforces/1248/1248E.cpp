#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

long long N, P, ans[100006];
pair<long long, int> t[100006];
priority_queue<pair<long long, int>> pq;
int main() {
	scanf("%d %d", &N, &P);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t[i].first);
		t[i].second = -i;
		t[i].first = -t[i].first;
		pq.push(t[i]);
	}
	long long time = 0;
	while(!pq.empty()) {
		if (-pq.top().first < time) {
			pair<long long, int> k = pq.top();
			//cout << time << endl;
			//cout << k.first << " " << k.second << endl;
			k.first = -time;
			pq.pop();
			pq.push(k);
		} else {
			pair<long long, int> k = pq.top();
			ans[-k.second] = -k.first + P;
			time = -k.first + P;
			pq.pop();
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
	return 0;
}
