#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct ele {
	unsigned int val;
	ele(): val(0){}
	ele(int a): val(a) {}
	
	ele operator + (const ele &b) {
		return val ^ b.val;
	}
	
	ele& operator += (const ele &b) {
		val ^= b.val;
        return *this;
    }
	
	ele operator - (const ele &b) {
		return val ^ b.val;
	}
	
	ele& operator -= (const ele &b) {
		val ^= b.val;
        return *this;
    }
	
	ele operator * (ele const &b) {
		return val & b.val;
	}
};

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
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < b.col; j++) {
				for (int k = 0; k < col; k++) {
					temp.val[i][j] += val[i][k] * b.val[k][j];
				}
			}
		}
		return temp;
	}

	
	Matrix pow(long long r) const {
		if (r == 1) {
			return *this;
		}
		
		if (r & 1) {
			Matrix temp = *this;
			return temp * pow(r - 1);
		} else {
			Matrix temp = pow(r / 2);
			return temp * temp;
		}
	}
	
	void print() {
		printf("%d %d\n", row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << val[i][j].val << " ";
			}
			cout << endl;
		}
	}
};

int k, m;

int main() {
	scanf("%d %d", &k, &m);
	Matrix<ele> a(k, k, 0), c(k, k, 0);
	for (int i = 0; i < k; i++) {
		unsigned int t;
		scanf("%u", &t);
		a.val[k - i - 1][0] = t;
	}
	for (int i = 0; i < k; i++) {
		unsigned int t;
		scanf("%u", &t);
		c.val[0][i] = t;
	}
	for (int i = 0; i < k - 1; i++) {
		c.val[i + 1][i] = UINT_MAX;
	}
	if (m <= k) {
		printf("%u\n", a.val[k - m][0].val);
		return 0;
	}
	Matrix<ele> b = c.pow(m - k);
	b = b * a;
	printf("%u\n", b.val[0][0].val);
	return 0;
}