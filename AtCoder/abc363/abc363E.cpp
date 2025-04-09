#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii>> pq;
int h, w, y, a[1004][1004];

int p[4] = {1, 0, -1, 0};
int q[4] = {0, 1, 0, -1};

int main() {
	scanf("%d %d %d", &h, &w, &y);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &a[i][j]);
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
				pq.push({a[i][j], i * w + j});
				a[i][j] = -1;
			}
		}
	}
	
	int sum = 0;
	for (int i = 1; i <= y; i++) {
		while (!pq.empty() && pq.top().first <= i) {
			auto pos = pq.top().second;
			pq.pop();
			sum++;
			
			int u = pos / w;
			int v = pos % w;
			a[u][v] = -1;
			
			for (int j = 0; j < 4; j++) {
				int new_u = u + p[j];
				int new_v = v + q[j];
				if (new_u < 0 || new_u >= h || new_v < 0 || new_v >= w) {
					continue;
				}
				
				if (a[new_u][new_v] == -1) {
					continue;
				}
				
				pq.push({a[new_u][new_v], new_u * w + new_v});
				a[new_u][new_v] = -1;
			}
		}
		
		printf("%d\n", h * w - sum);
	}
	
	return 0;
}