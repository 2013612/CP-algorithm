#include<iostream>
#include<vector>
using namespace std;

bool check(int x, int y, int size, int sum[][603]) {
    int leftTop = sum[x + size - 1][y + size - 1] + sum[x - 1][y - 1] - sum[x - 1][y + size - 1] - sum[x + size - 1][y - 1];

    int leftBottom = sum[x + size * 2 - 1][y + size - 1] + sum[x + size - 1][y - 1] - sum[x + size - 1][y + size - 1] - sum[x + size * 2 - 1][y - 1];

    int rightTop = sum[x + size - 1][y + size * 2 - 1] + sum[x - 1][y + size - 1] - sum[x - 1][y + size * 2 - 1] - sum[x + size - 1][y + size - 1];

    int rightBottom = sum[x + size * 2 - 1][y + size * 2 - 1] + sum[x + size - 1][y + size - 1] - sum[x + size - 1][y + size * 2 - 1] - sum[x + size * 2 - 1][y + size - 1];

    bool temp1 = ((leftTop + leftBottom + rightTop) == size * size * 3);
    bool temp2 = ((leftTop + leftBottom + rightBottom) == size * size * 3);
    bool temp3 = ((leftTop + rightBottom + rightTop) == size * size * 3);
    bool temp4 = ((rightBottom + leftBottom + rightTop) == size * size * 3);
    return temp1 || temp2 || temp3 || temp4;
}

int solution(vector< vector<bool> > &A) {
    int ans = 0;
    int N = A.size();
    int M = A[0].size();
    int sum[603][603];

    for (int i = 0; i < 600; i++) {
        for (int j = 0; j < 600; j++) {
            sum[i][j] = 0;
        }
    }

    for (int k = 1; k < N + M - 1; k++) {
        for (int i = 0; i < N; i++) {
            sum[i + 1][k - i + 1] = sum[i][k - i + 1] + sum[i + 1][k - i] - sum[i][k - i];
            if (A[i][k - i]) {
                sum[i + 1][k - i + 1]++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = ans + 1; ; k++) {
                if (i + k >= N || j + k >= N) break;
                if (check(i, j, k, sum)) {
                    ans = k;
                } else {
                    break;
                }
            }
        }
    }

    return ans;
}

int main() {
	return 0;
}


