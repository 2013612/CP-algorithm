#include<iostream>
#include<vector>
using namespace std;

const int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int N;
vector<string> board(8, "........");
bool has[10];

bool valid(int x, int y) {
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

bool check_queen(int a, int b) {
	for (int i = 0; i < 8; i++) {
		for (int j = 1; valid(a + j * x[i], b + j * y[i]); j++) {
			if (board[a + j * x[i]][b + j * y[i]] == 'Q') {
				return false;
			}
		}
	}
	return true;
}

bool check_board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 'Q') {
				if (!check_queen(i, j)) {
					return false;
				}
			}
		}
	}
	return true;
}

void solve(int row) {
	if (row == 8) {
		if (check_board()) {
			for (int i = 0; i < 8; i++) {
				cout << board[i] << endl;
			}
		}
		return;
	}
	if (has[row]) {
		solve(row + 1);
		return;
	}
	for (int i = 0; i < 8; i++) {
		board[row][i] = 'Q';
		solve(row + 1);
		board[row][i] = '.';
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		board[a][b] = 'Q';
		has[a] = true;
	}
	solve(0);
	return 0;
}
