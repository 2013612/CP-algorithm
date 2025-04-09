#include<iostream>
#include<set>
using namespace std;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int n, m, ans;
string s[1003];
bool visited[1003][1003];
set<pair<int, int>> mag;

bool in(int a, int b) {
	return a >= 0 && a < n && b >= 0 && b < m;
}

int dfs(int a, int b) {
	if (visited[a][b]) {
		return 0;
	}
	
	int cnt = 1;
	
	for (int i = 0; i < 4; i++) {
		int new_a = a + x[i];
		int new_b = b + y[i];
		if (in(new_a, new_b) && s[new_a][new_b] == '#') {
			mag.insert({a, b});
			return 0;
		}
	}
	
	visited[a][b] = true;
	
	for (int i = 0; i < 4; i++) {
		int new_a = a + x[i];
		int new_b = b + y[i];
		if (in(new_a, new_b) && !visited[new_a][new_b]) {
			cnt += dfs(new_a, new_b);
		}
	}
	
	return cnt;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != '#') {
				mag.clear();
				ans = max<int>(ans, dfs(i, j) + mag.size());
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}