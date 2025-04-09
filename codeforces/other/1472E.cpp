#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

int T, N, ans[200006];
pair< pair<int, int>, int> a[200006];

bool f(pair< pair<int, int>, int> x, pair< pair<int, int>, int> y) {
	if (x.first == y.first) {
		return x > y;
	} else {
		if (x.first.second == y.first.second) {
			return x.first.first > y.first.first;
		} else {
			return x.first.second > y.first.second;
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		priority_queue<pair< pair<int, int>, int>, vector<pair< pair<int, int>, int>>, greater<pair< pair<int, int>, int>>> pq;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d %d", &a[j].first.first, &a[j].first.second);
			a[j].second = j + 1;
			pq.push(a[j]);
			pq.push(make_pair(make_pair(a[j].first.second, a[j].first.first), j + 1));
		}
		sort(a, a + N, f);
		for (int j = 0; j < N; j++) {
			if (pq.empty()) {
				ans[a[j].second] = -1;
				continue;
			}
			if (pq.top().first.second >= a[j].first.second) {
				pq.pop();
				j--;
			} else {
				if (pq.top().first.first >= a[j].first.first) {
					ans[a[j].second] = -1;
				} else {
					ans[a[j].second] = pq.top().second;
				}
			}
		}
		for (int j = 1; j <= N; j++) {
			printf("%d ", ans[j]);
		}
		printf("\n");
	}
	
	return 0;
}
