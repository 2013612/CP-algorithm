#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, l, dis[200005][2], min_odd, sum, max_sum[2];
vector<int> v[200005];

void solve() {
	scanf("%d %d %d", &n, &m, &l);
	
	min_odd = 1e9;
	sum = 0;
	for (int i = 0; i < n; i++) {
		dis[i][0] = dis[i][1] = -1;
		v[i].clear();
	}
	dis[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	
	for (int i = 0; i < l; i++) {
		int k;
		scanf("%d", &k);
		sum += k;
		
		if (k & 1) {
			min_odd = min(min_odd, k);
		}
	}
	
	if (sum & 1) {
		if (min_odd < 1e7) {
			max_sum[0] = sum - min_odd;
		} else {
			max_sum[0] = -1;
		}
		
		max_sum[1] = sum;
	} else {
		max_sum[0] = sum;
		
		if (min_odd < 1e7) {
			max_sum[1] = sum - min_odd;
		} else {
			max_sum[1] = -1;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	while (q.size()) {
		auto [x, y] = q.front();
		q.pop();
		
		for (auto next: v[x]) {
			if (dis[next][(y + 1) % 2] == -1) {
				dis[next][(y + 1) % 2] = y + 1;
				q.push({next, y + 1});
			}
		}
	}
	
	string s;
	for (int i = 0; i < n; i++) {
		bool can = false;
		if (max_sum[0] >= 0) {
			if (dis[i][0] >= 0 && max_sum[0] >= dis[i][0]) {
				can = true;
			}
		}
		
		if (max_sum[1] >= 0) {
			if (dis[i][1] >= 0 && max_sum[1] >= dis[i][1]) {
				can = true;
			}
		}
		
		if (can) {
			printf("1");
		} else {
			printf("0");
		}
	}
	
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}