#include<iostream>
using namespace std;

int R, C, board[100][100];

bool check_board(int r, int c) {
	int k = board[1][1];
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (board[i][j] != k) {
				return false;
			}
		}
	}
	return true;
}

void flip(int quo, int rem) {
	board[quo][rem + 1] = 1 - board[quo][rem + 1];
	board[quo + 1][rem] = 1 - board[quo + 1][rem];
	board[quo + 1][rem + 1] = 1 - board[quo + 1][rem + 1];
	board[quo + 1][rem + 2] = 1 - board[quo + 1][rem + 2];
	board[quo + 2][rem + 1] = 1 - board[quo + 2][rem + 1];
}

bool flip_board(int r, int c, int choice) {
	for (int i = 0; i < r*c; i++) {
		if (choice & (1 << i)) {
			int quo = i / c;
			int rem = i % c;
			flip(quo, rem);
		}
	}
	return check_board(r, c);
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	bool success = false;
	for (int i = 0; i < (1 << R*C); i++) {
		if (flip_board(R, C, i)) {
			for (int j = 0; j < R*C; j++) {
				if (i & (1 << j)) {
					int quo = j / C;
					int rem = j % C;
					cout << quo << " " << rem << endl;
				}
			}
			success = true;
			break;
		} else {
			flip_board(R, C, i);
		}
		if (i == (1 << R*C) - 1) {
			cout << "NO" << endl;
		}
	}
	return 0;
}
