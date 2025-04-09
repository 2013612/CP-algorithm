#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int N, M, spdist[103][103][103];
vector<pair<int, int>> E[100006];
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int temp1, temp2, temp3;
		scanf("%d %d %d", &temp1, &temp2, &temp3);
		E[temp1].push_back(make_pair(temp2, temp3));
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				spdist[i][j][0] = 0;
			} else {
				spdist[i][j][0] = 1e9;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (auto x:E[i]) {
			spdist[i][x.first][0] = x.second;
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				spdist[i][j][k] = min(spdist[i][j][k - 1], spdist[i][k][k - 1] + spdist[k][j][k - 1]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << spdist[i][j][N] << " ";
		}
		cout << endl;
	}
	return 0;
}
