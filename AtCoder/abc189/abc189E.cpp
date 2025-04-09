#include<iostream>
using namespace std;

long long N, M, Q, pt[200006][2];
long long tran1[10], tran2[10], tran3[10], tran4[10], mat[200006][10], add[200006][10];

void op1(int index) {
	mat[index][0] = tran1[0] * mat[index - 1][0] + tran1[1] * mat[index - 1][2];
	mat[index][1] = tran1[0] * mat[index - 1][1] + tran1[1] * mat[index - 1][3];
	mat[index][2] = tran1[2] * mat[index - 1][0] + tran1[3] * mat[index - 1][2];
	mat[index][3] = tran1[2] * mat[index - 1][1] + tran1[3] * mat[index - 1][3];
	add[index][0] = tran1[0] * add[index - 1][0] + tran1[1] * add[index - 1][2];
	add[index][2] = tran1[2] * add[index - 1][0] + tran1[3] * add[index - 1][2];
}

void op2(int index) {
	mat[index][0] = tran2[0] * mat[index - 1][0] + tran2[1] * mat[index - 1][2];
	mat[index][1] = tran2[0] * mat[index - 1][1] + tran2[1] * mat[index - 1][3];
	mat[index][2] = tran2[2] * mat[index - 1][0] + tran2[3] * mat[index - 1][2];
	mat[index][3] = tran2[2] * mat[index - 1][1] + tran2[3] * mat[index - 1][3];
	add[index][0] = tran2[0] * add[index - 1][0] + tran2[1] * add[index - 1][2];
	add[index][2] = tran2[2] * add[index - 1][0] + tran2[3] * add[index - 1][2];
}

void op3(int index, int p) {
	mat[index][0] = tran3[0] * mat[index - 1][0] + tran3[1] * mat[index - 1][2];
	mat[index][1] = tran3[0] * mat[index - 1][1] + tran3[1] * mat[index - 1][3];
	mat[index][2] = tran3[2] * mat[index - 1][0] + tran3[3] * mat[index - 1][2];
	mat[index][3] = tran3[2] * mat[index - 1][1] + tran3[3] * mat[index - 1][3];
	add[index][0] = tran3[0] * add[index - 1][0] + tran3[1] * add[index - 1][2] + 2 * p;
	add[index][2] = tran3[2] * add[index - 1][0] + tran3[3] * add[index - 1][2];
}

void op4(int index, int p) {
	mat[index][0] = tran4[0] * mat[index - 1][0] + tran4[1] * mat[index - 1][2];
	mat[index][1] = tran4[0] * mat[index - 1][1] + tran4[1] * mat[index - 1][3];
	mat[index][2] = tran4[2] * mat[index - 1][0] + tran4[3] * mat[index - 1][2];
	mat[index][3] = tran4[2] * mat[index - 1][1] + tran4[3] * mat[index - 1][3];
	add[index][0] = tran4[0] * add[index - 1][0] + tran4[1] * add[index - 1][2];
	add[index][2] = tran4[2] * add[index - 1][0] + tran4[3] * add[index - 1][2] + 2 * p;
}

void cal(int op, int index) {
	long long x = mat[op][0] * pt[index][0] + mat[op][1] * pt[index][1] + add[op][0];
	long long y = mat[op][2] * pt[index][0] + mat[op][3] * pt[index][1] + add[op][2];
	printf("%lld %lld\n", x, y);
}

int main() {
	tran1[0] = 0;
	tran1[1] = 1;
	tran1[2] = -1;
	tran1[3] = 0;
	tran2[0] = 0;
	tran2[1] = -1;
	tran2[2] = 1;
	tran2[3] = 0;
	tran3[0] = -1;
	tran3[1] = 0;
	tran3[2] = 0;
	tran3[3] = 1;
	tran4[0] = 1;
	tran4[1] = 0;
	tran4[2] = 0;
	tran4[3] = -1;
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[0][3] = 1;
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld %lld", &pt[i][0], &pt[i][1]);
	}
	scanf("%lld", &M);
	for (int i = 1; i <= M; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == 1) {
			op1(i);
		} else if (temp == 2) {
			op2(i);
		} else {
			int temp2;
			scanf("%d", &temp2);
			if (temp == 3) {
				op3(i, temp2);
			} else {
				op4(i, temp2);
			}
		}
	}
	scanf("%lld", &Q);
	for (int i = 0; i < Q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cal(a, b);
	}
	return 0;
}
