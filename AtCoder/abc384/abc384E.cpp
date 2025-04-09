#include<iostream>
#include<queue>
using namespace std;

const int u[4] = {1, 0, -1, 0};
const int v[4] = {0, 1, 0, -1};

int h, w, x, p, q;
long long a[503][503];
priority_queue<pair<long long, pair<int, int>>> pq;

int main() {
	scanf("%d %d %d", &h, &w, &x);
	scanf("%d %d", &p, &q);
	p--;
	q--;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	
	long long ans = a[p][q];
	a[p][q] = 0;
	pq.push({0, {p, q}});
	
	while (!pq.empty()) {
		auto [str, co] = pq.top();
		pq.pop();
		str = -str;
		if (str >= (ans + x - 1) / x) {
			break;
		}
		ans += str;
		
		for (int i = 0; i < 4; i++) {
			int new_u = co.first + u[i];
			int new_v = co.second + v[i];
			if (new_u < 0 || new_v < 0 || new_u >= h || new_v >= w || a[new_u][new_v] <= 0) {
				continue;
			}
			pq.push({-a[new_u][new_v], {new_u, new_v}});
			a[new_u][new_v] = 0;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}