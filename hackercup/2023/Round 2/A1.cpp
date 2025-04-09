#include<iostream>
#include<algorithm>
using namespace std;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

string board[3010];
int cnt[3010][3010];
bool visited[3010][3010];

void clear() {
	for (int i = 0; i < 3010; i++) {
		for (int j = 0; j < 3010; j++) {
			cnt[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

bool dfs(int r, int c, int &sum, int &e_r, int &e_c) {
//	printf("^ %d %d\n", r, c);
	visited[r][c] = true;
	sum++;
	bool can = true;
	for (int i = 0; i < 4; i++) {
		int new_r = r + x[i];
		int new_c = c + y[i];
		
//		printf("& %d %d %d %d\n", r, c, new_r, new_c);
		
		if (visited[new_r][new_c]) {
			continue;
		}
		
		if (board[new_r][new_c] == 'W') {
			can = dfs(new_r, new_c, sum, e_r, e_c) && can;
		} else if (board[new_r][new_c] == '.') {
//			printf("! %d %d %d %d %d %d\n", r, c, new_r, new_c, e_r, e_c);
			if (new_r == e_r && new_c == e_c) {
				continue;
			}
			
			if (e_r != -1) {
				can = false;
			} else {
				e_r = new_r;
				e_c = new_c;
			}
		}
	}
	
//	printf("# %d %d %c\n", r, c, can ? 'Y' : 'N');
	
	return can;
}

void solve() {
	int r, c;
	scanf("%d %d", &r, &c);
	board[0] = string(3010, 'B');
	board[r + 1] = string(3010, 'B');
	for (int i = 1; i <= r; i++) {
		string s;
		cin >> s;
		board[i] = "B" + s + "B";
	}
	clear();
	
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (board[i][j] == 'W' && !visited[i][j]) {
//				printf("$ %d %d\n", i, j);
				int sum = 0;
				int e_r = -1;
				int e_c = -1;
				if (dfs(i, j, sum, e_r, e_c)) {
					cnt[e_r][e_c] += sum;
				}
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			ans = max(ans, cnt[i][j]);
		}
	}
	
	if (ans > 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	freopen("ready_go_part_1_input.txt", "r", stdin);
	freopen("ready_go_part_1_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}