#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

int n, m, dis[1003][1003];
string s[1003];
pii st, gl, dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i <= m + 1; i++) {
		s[0].push_back('1');
		s[n + 1].push_back('1');
	}
	for (int i = 1; i <= n; i++) {
		s[i].push_back('1');
		for (int j = 1; j <= m; j++) {
			char t;
			scanf("%c", &t);
			if (t == ' ' || t == '\n') {
				j--;
				continue;
			}
			s[i].push_back(t);
			dis[i][j] = -1;
			if (t == 's') {
				st = {i, j};
				dis[i][j] = 0;
			} else if (t == 'g') {
				gl = {i, j};
			}
		}
		s[i].push_back('1');
	}
	queue<pii> q;
	q.push(st);
	while (!q.empty() && dis[gl.first][gl.second] < 0) {
		auto [i, j] = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int r = i + dir[k].first;
			int c = j + dir[k].second;
			if (dis[r][c] < 0 && (s[r][c] == '0' || s[r][c] == 'g')) {
				dis[r][c] = dis[i][j] + 1;
				q.push({r, c});
			}
		}
	}
	if (dis[gl.first][gl.second] > 0) {
		printf("%d\n", dis[gl.first][gl.second]);
	} else {
		printf("Fail\n");
	}
	return 0;
}