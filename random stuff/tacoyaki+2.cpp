#include<iostream>
#include<vector>
#include<utility>
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
	board[quo - 1][rem] = 1 - board[quo - 1][rem];
	board[quo][rem - 1] = 1 - board[quo][rem - 1];
	board[quo][rem] = 1 - board[quo][rem];
	board[quo][rem + 1] = 1 - board[quo][rem + 1];
	board[quo + 1][rem] = 1 - board[quo + 1][rem];
}

void flip_board(int r, int c, int choice) {
	for (int i = 0; i < r*c; i++) {
		if (choice & (1 << i)) {
			int quo = i / c + 1;
			int rem = i % c + 1;
			flip(quo, rem);
		}
	}
}

void print_board(int r, int c) {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool flip_board2(int r1, int r2, int c, int choice, int k) {
	vector<pair<int, int>> move;
	//print_board(r2, c);
	for (int i = r1; i <= r2 - 1; i++) {
		for (int j = 1; j <= c; j++) {
			if (board[i][j] != k) {
				flip(i + 1, j);
				//print_board(r2, c);
				move.push_back(make_pair(i + 1, j));
			}
		}
	}
	if (check_board(r2, c)) {
		for (int i = 0; i < c; i++) {
			if (choice & (1 << i)) {
				int quo = i / c + 1;
				int rem = i % c + 1;
				cout << quo << " " << rem << endl;
			}
		}
		for (int i = 0; i < move.size(); i++) {
			cout << move[i].first << " " << move[i].second << endl;
		}
		return true;
	} else {
		for (int i = 0; i < move.size(); i++) {
			flip(move[i].first, move[i].second);
		}
		return false;
	}
}

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	bool success = false;
	for (int i = 0; i < (1 << C); i++) {
		flip_board(1, C, i);
		if (flip_board2(1, R, C, i, 0) || flip_board2(1, R, C, i, 1)) {
			success = true;
			break;
		} else {
			flip_board(1, C, i);
		}
		if (i == (1 << C) - 1) {
			cout << "NO" << endl;
		}
	}
	/*for (int i = 0; i < (1 << 2*C); i++) {
		flip_board(2, C, i);
		if (check_board(1, C)) {
			//cout << i << endl;s
			if (flip_board2(2, R, C, i)){
				success = true;
				break;
			}	
		} else {
			flip_board(2, C, i);
		}
		if (i == (1 << 2*C) - 1) {
			cout << "NO" << endl;
		}
	}*/
	return 0;
}
