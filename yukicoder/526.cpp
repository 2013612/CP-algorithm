#include<iostream>
#include<vector>
using namespace std;

int n, m;
long long ans;
vector<vector<long long>> a = {{1, 1}, {1, 0}}, b = {{1, 0}};

struct matrix{
	int row, col;
	long long size;
	vector<vector<long long>> val;
	
	matrix(int x, int y) {
		row = x;
		col = y;
		size = 1;
		while (size < max(row, col)) {
			size *= 2;
		}
		vector<vector<long long>> temp(size, vector<long long>(size, 0));
		val = temp;
	}
	
	matrix(vector<vector<long long>> z) {
		row = z.size();
		for (auto x : z) {
			col = max(col, (int) x.size());
		}
		size = 1;
		while (size < max(row, col)) {
			size *= 2;
		}
		for (int i = 0; i < size; i++) {
			vector<long long> temp = vector<long long>(size, 0);
			if (i < z.size()) {
				z[i].resize(size, 0);
				temp = z[i];
			}
			val.push_back(temp);
		}
	}
	
	matrix operator + (matrix const &obj) {
		matrix temp(row, col);
		if (row == obj.row && col == obj.col) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					temp.val[i][j] = (val[i][j] + obj.val[i][j]) % m;
				}
			}
		} else {
			cout << "wrong size!" << endl;
		}
		return temp;
	}
	
	matrix operator - (matrix const &obj) {
		matrix temp(row, col);
		if (row == obj.row && col == obj.col) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					temp.val[i][j] = (val[i][j] - obj.val[i][j]) % m;
				}
			}
		} else {
			cout << "wrong size!" << endl;
		}
		return temp;
	}
	
	void print() {
		cout << row << " " << col << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << val[i][j] << " "; 
			}
			cout << endl;
		}
	}
} ma(a), mb(b);

matrix obtain(matrix a, int p, int q, int r, int s) {
	matrix temp(r, s);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			temp.val[i][j] = a.val[p + i][q + j];
		}
	}
	return temp;
}

matrix combine(matrix a, matrix b, matrix c, matrix d) {
	int row = a.row + c.row;
	int col = a.col + b.col;
	matrix temp(row, col);
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < a.col; j++) {
			temp.val[i][j] = a.val[i][j];
		}
	}
	for (int i = 0; i < b.row; i++) {
		for (int j = 0; j < b.col; j++) {
			temp.val[i][a.col + j] = b.val[i][j];
		}
	}
	for (int i = 0; i < c.row; i++) {
		for (int j = 0; j < c.col; j++) {
			temp.val[a.row + i][j] = c.val[i][j];
		}
	}
	for (int i = 0; i < d.row; i++) {
		for (int j = 0; j < d.col; j++) {
			temp.val[a.row + i][a.col + j] = d.val[i][j];
		}
	}
	return temp;
}

matrix mul(matrix a, matrix b) {
	int r = a.row;
	int c = a.col;
	int size = a.size;
	matrix temp(r, c);
	if (temp.size == 1) {
		temp.val[0][0] = a.val[0][0] * b.val[0][0] % m;
		return temp;
	}
	matrix a11 = obtain(a, 0, 0, size/2, size/2);
	matrix a12 = obtain(a, 0, size/2, size/2, size/2);
	matrix a21 = obtain(a, size/2, 0, size/2, size/2);
	matrix a22 = obtain(a, size/2, size/2, size/2, size/2);
	matrix b11 = obtain(b, 0, 0, size/2, size/2);
	matrix b12 = obtain(b, 0, size/2, size/2, size/2);
	matrix b21 = obtain(b, size/2, 0, size/2, size/2);
	matrix b22 = obtain(b, size/2, size/2, size/2, size/2);
	matrix fxxk1 = mul(a11, b12 - b22);
	matrix fxxk2 = mul(a11 + a12, b22);
	matrix fxxk3 = mul(a21 + a22, b11);
	matrix fxxk4 = mul(a22, b21 - b11);
	matrix fxxk5 = mul(a11 + a22, b11 + b22);
	matrix fxxk6 = mul(a12 - a22, b21 + b22);
	matrix fxxk7 = mul(a11 - a21, b11 + b12);
	temp = combine(fxxk5 + fxxk4 - fxxk2 + fxxk6, fxxk1 + fxxk2, fxxk3 + fxxk4, fxxk1 + fxxk5 - fxxk3 - fxxk7);
	temp.row = a.row;
	temp.col = a.col;
	return temp;
}

matrix pow(matrix a, int b) {
	if (b == 1) {
		return a;
	}
	if (b & 1) {
		return mul(a, pow(a, b - 1));
	} else {
		matrix temp = pow(a, b / 2);
		return mul(temp, temp);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	matrix t = pow(ma, n - 2);
	t = mul(t, mb);
	printf("%lld\n", (t.val[0][0] + m) % m);
	return 0;
}