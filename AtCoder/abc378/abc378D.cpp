#include<iostream>
using namespace std;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int h, w, k, ans;
string s[20];
bool visited[20][20];

void find(int u, int v, int step) {
	if (step == k) {
		ans++;
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int new_u = u + x[i];
		int new_v = v + y[i];
		if (s[new_u][new_v] == '.' && !visited[new_u][new_v]) {
			visited[new_u][new_v] = true;
			find(new_u, new_v, step + 1);
			visited[new_u][new_v] = false;
		}
	}
}

int main() {
	scanf("%d %d %d", &h, &w, &k);
	
	s[0] = s[h + 1] = "###################";
	
	for (int i = 1; i <= h; i++) {
		cin >> s[i];
		s[i] = "#" + s[i] + "#";
	}
	
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (s[i][j] == '.') {
				visited[i][j] = true;
				find(i, j, 0);
				visited[i][j] = false;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}