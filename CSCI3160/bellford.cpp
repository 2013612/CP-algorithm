#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int N, M, spdist[100006], Start;
vector<pair<int, int>> E[100006];

void bellford() {
	for (int i = 0; i < N - 1; i++) {
		bool change = false;
		//cout << i << endl;
		for (int j = 1; j <= N; j++) {
			for (auto x:E[j]) {
				//cout << "!" << j << " " << x.first << " " << spdist[x.first] << " " << spdist[j] + x.second << endl;
				if (spdist[x.first] > spdist[j] + x.second) {
					change = true;
					spdist[x.first] = spdist[j] + x.second;
				}
			}
		}
		if (!change) {
			break;
		}
	}
	return;
}

int main() {
	scanf("%d %d %d", &N, &M, &Start);
	for (int i = 0; i < M; i++) {
		int temp1, temp2, temp3;
		scanf("%d %d %d", &temp1, &temp2, &temp3);
		E[temp1].push_back(make_pair(temp2, temp3));
	}
	for (int i = 1; i <= N; i++) {
		if (i != Start) {
			spdist[i] = 1e9;
		} else {
			spdist[i] = 0;
		}
	}
	bellford();
	for (int i = 1; i <= N; i++) {
		cout << i << " " << spdist[i] << endl;
	}
	return 0;
}
