#include<iostream>
#include<vector>
using namespace std;

int N, M, K;

template <class T>
struct Matrix {
	int row, col;
	long long size;
	vector<vector<T>> val;
	
	Matrix(int x, int y) {
		*this = Matrix(x, y, T{});
	}
	
	Matrix(int x, int y, T init): row(x), col(y) {
		size = 1;
		while (size < max(row, col)) {
			size *= 2;
		}
		val = vector<vector<T>>(size, vector<T>(size, init));
	}
	
	Matrix(const vector<vector<T>> &z) {
		int r = z.size();
		int c = 0;
		for (auto x : z) {
			c = max(col, (int) x.size());
		}
		*this = Matrix(r, c, z);
	}
	
	Matrix(int x, int y, const vector<vector<T>> &z): row(x), col(y) {
		size = 1;
		while (size < max(row, col)) {
			size *= 2;
		}
		for (int i = 0; i < size; i++) {
			vector<T> temp = vector<T>(size, T{});
			temp = z[i];
			if (i < z.size()) {
				temp.resize(size, T{});
			}
			val.push_back(temp);
		}
	}
	
	static Matrix e(int n) {
        Matrix a(n, n, T{});
        for (int i = 0; i < n; i++) {
        	a[i][i] = T{1};
		}
        return a;
    }
    
    bool operator == (const Matrix &b) {
    	for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (val[i][j] != b.val[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	
	bool operator != (const Matrix &b) {
    	return !(this == b);
	}
	
	Matrix& operator += (const Matrix &b) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				val[i][j] += b.val[i][j];
			}
		}
        return *this;
    }
	
	Matrix operator + (Matrix const &b) {
		return Matrix(row, col, (*this).val) += b;
	}
	
	Matrix& operator -= (const Matrix &b) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				val[i][j] -= b.val[i][j];
			}
		}
        return *this;
    }
	
	Matrix operator - (Matrix const &b) {
		return Matrix(row, col, (*this).val) -= b;
	}
	
	Matrix operator * (Matrix const &b) {
		Matrix temp(row, b.col);
		
		if (temp.size == 1) {
			temp.val[0][0] = val[0][0] * b.val[0][0];
			return temp;
		}
		
		Matrix a11 = getSubMatrix(0, 0, (row + 1) / 2, (col + 1) / 2);
		Matrix a12 = getSubMatrix(0, (col + 1) / 2, (row + 1) / 2, (col + 1) / 2);
		Matrix a21 = getSubMatrix((row + 1) / 2, 0, (row + 1) / 2, (col + 1) / 2);
		Matrix a22 = getSubMatrix((row + 1) / 2, (col + 1) / 2, (row + 1) / 2, (col + 1) / 2);
		
		Matrix b11 = b.getSubMatrix(0, 0, (b.row + 1) / 2, (b.col + 1) / 2);
		Matrix b12 = b.getSubMatrix(0, (b.col + 1) / 2, (b.row + 1) / 2, (b.col + 1) / 2);
		Matrix b21 = b.getSubMatrix((b.row + 1) / 2, 0, (b.row + 1) / 2, (b.col + 1) / 2);
		Matrix b22 = b.getSubMatrix((b.row + 1) / 2, (b.col + 1) / 2, (b.row + 1) / 2, (b.col + 1) / 2);
		
		Matrix fxxk1 = a11 * (b12 - b22);
		Matrix fxxk2 = (a11 + a12) * b22;
		Matrix fxxk3 = (a21 + a22) * b11;
		Matrix fxxk4 = a22 * (b21 - b11);
		Matrix fxxk5 = (a11 + a22) * (b11 + b22);
		Matrix fxxk6 = (a12 - a22) * (b21 + b22);
		Matrix fxxk7 = (a11 - a21) * (b11 + b12);
		
		temp = combine(fxxk5 + fxxk4 - fxxk2 + fxxk6, fxxk1 + fxxk2, fxxk3 + fxxk4, fxxk1 + fxxk5 - fxxk3 - fxxk7);
		// fix the change of size
		temp.row = row;
		temp.col = b.col;
		
		return temp;
	}
	
	Matrix getSubMatrix(int tl, int tr, int r, int c) const {
		Matrix temp(r, c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				temp.val[i][j] = val[tl + i][tr + j];
			}
		}
		return temp;
	}
	
	Matrix combine(Matrix a, Matrix b, Matrix c, Matrix d) {
		Matrix temp(a.row + c.row, a.col + b.col);
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
	
	Matrix pow(long long r) const {
		if (r == 0) {
			return e(row);
		}
//		if (r < 0) {
//			return inv().pow(-r);
//		}
		
		if (r & 1) {
			return (*this) * pow(r - 1);
		} else {
			Matrix temp = pow(r / 2);
			return temp * temp;
		}
	}
	
	// may overflow easily if using int
	T det() const {
		Matrix a = *this;
        T ans = T{1};
        T total = T{1};
        for (int i = 0; i < row - 1; i++) {
        	if (a.val[i][i] == 0) {
        		for (int j = i + 1; j < row; j++) {
        			if (a.val[j][i] != 0) {
        				swap(a.val[i], a.val[j]);
        				ans = -ans;
        				break;
					}
				}
			}
			if (a.val[i][i] == 0) {
				return 0;
			}

			for (int j = i + 1; j < row; j++) {
				for (int k = i + 1; k < col; k++) {
					a.val[j][k] = a.val[j][k] * a.val[i][i] - a.val[i][k] * a.val[j][i]; // may overflow here
				}
				a.val[j][i] = 0;
				total *= a.val[i][i]; // may overflow here
			}
			total /= a.val[i][i];
		}
		
		return ans * a.val[row - 1][row - 1] / total;
    }
	
	void print() {
		printf("%d %d\n", row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << val[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	scanf("%d %d %d", &N, &M, &K);
	Matrix<int> a(N, M);
	Matrix<int> b(M, K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &a.val[i][j]);
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &b.val[i][j]);
		}
	}
	(a * b).print();
	vector<vector<int>> c = { { 1, 0, 2, -1 },
                      { 3, 0, 0, 5 },
                      { 2, 1, 4, -3 },
                      { 1, 0, 5, 0 } };
	cout << Matrix(c).det() << endl;
	return 0;
}
