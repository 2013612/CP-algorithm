#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, M, go[103][103];
string cell[103];

bool dfs(int a, int b) {
	if (a == N && b == M) {
		return true;
	}
	go[a][b] = 1;
	bool temp1 = false;
	bool temp2 = false;
	bool temp3 = false;
	bool temp4 = false;
	//printf("%d %d\n", a, b);
	//printf("%d %d %d %d\n", go[a - 1][b], go[a + 1][b], go[a][b - 1], go[a][b + 1]);
	if (go[a - 1][b] == 0 && cell[a - 1][b] != '#') {
		//cout << "#" << endl; 
		temp1 = dfs(a - 1, b);
	}
	if (go[a + 1][b] == 0 && cell[a + 1][b] != '#') {
		//cout << "$" << endl; 
		temp2 = dfs(a + 1, b);
	}
	if (go[a][b - 1] == 0 && cell[a][b - 1] != '#') {
		//cout << "%" << endl; 
		temp3 = dfs(a, b - 1);
	}
	if (go[a][b + 1] == 0 && cell[a][b + 1] != '#') {
		//cout << "^" << endl; 
		//printf("%d %d\n", a, b);
		temp4 = dfs(a, b + 1);
	}
	return temp1 || temp2 || temp3 || temp4;
}

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		for (int j = 1; j <= N; j++) {
			cin >> cell[j];
			cell[j] = "#" + cell[j] + "#";
		}
		for (int j = 0; j <= M; j++) {
			cell[0] = cell[0] + "#";
			cell[N + 1] = cell[N + 1] + "#";
		}
		bool ans = true;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (cell[j][k] == 'B') {
					if (cell[j - 1][k] == '.') cell[j - 1][k] = '#';
					if (cell[j][k - 1] == '.') cell[j][k - 1] = '#';
					if (cell[j + 1][k] == '.') cell[j + 1][k] = '#';
					if (cell[j][k + 1] == '.') cell[j][k + 1] = '#';
				}
			}
		}
		
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (cell[j][k] == 'G') {
					for (int r = 0; r <= N; r++) {
						for (int l = 0; l <= M; l++) {
							go[r][l] = 0;
						}
					}
					//printf("!%d %d\n", j, k);
					if (!dfs(j, k)) {
						//printf("!%d %d\n", j, k);
						ans = false;
						break;
					}
				} else if (cell[j][k] == 'B') {
					for (int r = 0; r <= N; r++) {
						for (int l = 0; l <= M; l++) {
							go[r][l] = 0;
						}
					}
					if (dfs(j, k)) {
						//printf("@%d %d\n", j, k);
						ans = false;
						break;
					} 
				}
			}
			if (!ans) break;
		}
		if (!ans) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
	return 0;
}
