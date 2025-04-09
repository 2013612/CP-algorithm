#include<iostream>
#include<queue>
using namespace std;

int n, ans[103][103];
string c[103];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	
	deque<pair<int, int>> q;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = -1;
			if (i == j) {
				ans[i][j] = 0;
				q.push_front({i, j});
			} else if (c[i][j] != '-') {
				ans[i][j] = 1;
				q.push_back({i, j});
			}
		}
	}
	
	while (!q.empty()) {
		auto x = q.front();
		q.pop_front();
		
		for (int i = 0; i < n; i++) {
			if (c[i][x.first] != '-') {
				for (int j = 0; j < n; j++) {
					if (c[x.second][j] == c[i][x.first] && ans[i][j] == -1) {
						ans[i][j] = ans[x.first][x.second] + 2;
						q.push_back({i, j});
					}
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}