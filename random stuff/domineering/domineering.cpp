/* CSCI1540
 *
 * Assignment: 3
 * Student ID: 1155093001
 * Name      : Wong Ki Long
 * Email     : 1155093001@link.cuhk.edu.hk
 *
 */
#include <iostream>
using namespace std;

int gridState(long long grid, int pos) {
	long long tmp, divisor;
	tmp = 1;
	divisor = 1;
	for (int i = 0; i <= 15 - pos; i++){ 
		divisor = divisor * 10;
	}
	tmp = grid / divisor; // locate the position of the digit
	grid = tmp % 10;
	return grid;
}

void displayGrid(long long grid){
	int quotient;
	quotient = 1;
	for (int i = 1; i <= 16; i++){ // cout the 4X4 grid
		quotient = gridState(grid, i); // identify the value of the digit
		switch (quotient) { // cout the character according to the state of the digit
			case 0:
				cout << ". ";
				break;
			case 1:
				cout << "O ";
			    break;
			case 2:
				cout << "X ";
				break;
		}
		if (i % 4 == 0){ // divide the 16 characters to 4 lines
			cout << endl;
		}
	}
}

bool isPlaceable(long long grid, int pos, int p){
	if (gridState(grid, pos) != 0) {
		return false;
	}
	if (p == 1) { // check whether it is placeable by player 1
		if (pos <= 12 && gridState(grid, pos + 4) == 0){
			return true;
		}
		else {
			return false;
		}
	}
	else { // check whether it is placeable by player 2
		if (pos < 16 && pos % 4 != 0 && gridState(grid, pos + 1) == 0){
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	long long grid, divisor;
	int pos, p;
	bool end = false;
	grid = 0;
	pos = 0;
	p = 1;
	displayGrid(grid); // display the empty grid
	cout << endl;
	while (end == false){
		cout << "Player " << p << ", make a move: "; // ask player to place a domino
		cin >> pos;
		divisor = 1;
		if (isPlaceable(grid, pos, p) == true){ // change the state of the digit if it is a valid move
			for (int i = 0; i <= 15 - pos; i++) {
				divisor = divisor * 10;
			}
			if (p == 1){
				grid = grid + divisor + divisor / 10000;
			}
			else {
				grid = grid + divisor * 2 + divisor /5 ;
			}
		}
		else { // avoid invalid move
			cout << "Invalid move! Try again." << endl;
			continue;
		}
		p = 3 - p; // change the player
		for (int i = 1; i < 17; i++){ // check whether the next player has valid move
			if (isPlaceable(grid, i, p) == true) {
				end = false;
				break;
			}
			else {
				end = true;
			}
		}
		displayGrid(grid); // display the 4x4 grid
		cout << endl;
		if (end == true) { // cout the winner
			cout << "Player " << 3 - p << " wins!"; 
		}

	}
	return 0;
}
