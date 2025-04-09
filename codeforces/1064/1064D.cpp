#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int N, M, R, C, X, Y, ans, a[2004][2004][3];
bool b[2004][2004];
char c[2004][2004];

struct f {
	bool operator() (pair <int, int> x, pair <int , int> y) {
		return a[x.first][x.second][2] > a[y.first][y.second][2];
	}
};

priority_queue<pair <int, int>, vector<pair<int, int>>, f> fxxk;

void update (int x, int y, int l, int r) {
	if (l > X || r > Y || x < 0 || y < 0 || x >= N || y >= M)  {
		return;
	}
	if (c[x][y] == '*') {
		return;
	}
	if (b[x][y]) {
		return;
	}
	b[x][y] = true;
	if (x > 0) {
		a[x - 1][y][0] = a[x][y][0];
		a[x - 1][y][1] = a[x][y][1];
		a[x - 1][y][2] = a[x][y][2] + 1;
	}
	if (y > 0) {
		a[x][y - 1][0] = a[x][y][0] + 1;
		a[x][y - 1][1] = a[x][y][1];
		a[x][y - 1][2] = a[x][y][2] + 1;
	}
	a[x + 1][y][0] = a[x][y][0];
	a[x + 1][y][1] = a[x][y][1];
	a[x + 1][y][2] = a[x][y][2] + 1;
	a[x][y + 1][0] = a[x][y][0];
	a[x][y + 1][1] = a[x][y][1] + 1;
	a[x][y + 1][2] = a[x][y][2] + 1;
	pair <int, int> temp (x - 1, y);
	if (x > 0) {
		if (!b[x - 1][y] && c[x - 1][y] == '.') {
			fxxk.push(temp);
		}
	}
	temp.first = x + 1;
	if (!b[x + 1][y] && c[x + 1][y] == '.') {
		fxxk.push(temp);
	}
	temp.first = x;
	temp.second = y - 1;
	if (y > 0) {
		if (!b[x][y - 1] && c[x][y - 1] == '.') {
			fxxk.push(temp);
		}
	}
	temp.second = y + 1;
	if (!b[x][y + 1] && c[x][y + 1] == '.') {
		fxxk.push(temp);
	}
	//printf ("@%d %d\n", x, y);
}

int main(){
	scanf("%d %d %d %d %d %d", &N, &M, &R, &C, &X, &Y);
	for (int i = 0; i < N; i++) {
		scanf("%s", c[i]);
	}
	pair <int, int> temp (R - 1, C - 1);
	fxxk.push(temp);
	while (!fxxk.empty()) {
		int x = fxxk.top().first;
		int y = fxxk.top().second;
		//printf("!%d %d\n", x, y);
		fxxk.pop();
		update(x, y, a[x][y][0], a[x][y][1]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (b[i][j]) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
