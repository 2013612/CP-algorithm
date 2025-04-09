#include <iostream>
#include <iomanip>
using namespace std;

const int N = 18;

void displayboard (char x[][N], int rowsize) { // function for cout the board
	for (int i = 0; i < N; i++){ // cout the English letters on the first row
		if (i == 0)
		cout << "   " << "A";
		else
		cout << " " << char(i + 'A');
	}
	cout << endl;
	for (int i = 0; i < N; i++){ 
		cout << setw(2) << i; // cout the numbers on the first column 
		for (int j = 0; j < N; j++){
			cout << " " << x[i][j]; // cout the board
		}
		cout << endl;
	}
}

void initializeboard (char x[][N], int rowsize){ // function for initial the board
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			x[i][j] = '.';
		}
	}
}

bool validmove (char position, char col, int row){ // function for check whether the move is valid
	if (int(col - 'A') < 0 || int(col - 'A') > N-1 || row > N-1 || row < 0){ // false if out of range
		return false;
	}
	if (position != '.'){ // false if there is a queen or attacked by other queens
		return false;
	}
	else{
		return true;
	}
}

bool updateboard (char x[][N], int rowsize, char y, int row){ // function for update the board
	int column = int(y - 'A');
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i == row|| j == column|| i - row == j - column|| i - row == column - j){ // denote with '=' if it is attacked by the queen
				x[i][j] = '=';
			}
		}
	}
	x[row][column] = 'Q'; // denote with 'Q' if it is placed
	bool enoughqueen = true;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (x[i][j] != '='){ 
				enoughqueen = true; // true if the row has queen or empty space
				break;
			}
			else 
				enoughqueen = false;
		}
		if (enoughqueen == false){ 
			break; // if there exists a row cannot place any queen
		}
	}
	bool enoughqueen2 = true;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (x[j][i] != '='){ 
				enoughqueen2 = true; // true if the column has queen or empty space
				break;
			}
			else 
				enoughqueen2 = false;
		}
		if (enoughqueen2 == false){ 
			break; // if there exists a column cannot place any queen
		}
	}
	if (enoughqueen == true && enoughqueen2 == true) // true if all columns and rows have queens or empty space
		return true;
	else
		return false;
}

int main() {
	char board[N][N];
	char col = 'A';
	int i, row = 0;
	bool finish = false;
	initializeboard (board, N); // initial the board
	displayboard (board, N); // cout the board
	cout << "No. of Queens = " << i << endl; // cout the number of queens placed
	while (finish == false){
		cout << "Make a move (col row): "; // ask for position to put the queen
		cin >> col >> row; 
		if (validmove (board[row][col - 'A'], col, row) == false){ // check whether the position is placeable
			cout << "Invalid. Try again!" << endl; // reject if it is invalid	
			continue; // ask for the position again
		}
		if (updateboard(board, N, col, row) == false){ // update the board and check whether there is a row or column has no queen and empty space
			finish = true;
		}
		++i;
		displayboard (board, N); // cout the updated board
		cout << "No. of Queens = " << i << endl;
		if (i == 18){ // end the loop if enough queens are placed
			finish = true;
		}
	}
	if (i == 18){ // cout the sentence according to number of queens placed
		cout << "Yeah! Problem solved.";
	}
	else {
		cout << "Oops! Not enough queens.";
	}
	return 0;
}
