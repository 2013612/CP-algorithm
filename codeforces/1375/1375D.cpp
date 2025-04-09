#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, T, a[2004], b[5004], mex;
vector<int> ans;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		bool done = false;
		ans.clear();
		for (int j = 0; j <= N; j++) {
			b[j] = 0;
		}
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			b[a[j]]++;
		}
		for (int j = 0; j <= N; j++) {
			if (b[j] == 0) {
				mex = j;
				//printf("@%d\n", mex);
				break;
			}
		}
		for (int j = 1; j < N; j++) {
			if (a[j - 1] > a[j]) break;
			if (j == N - 1) {
				printf("0\n\n");
				done = true;
			}
		}
		if (done) continue;
		/*if (mex == N) {
			int temp = a[N - 1];
			a[N - 1] = mex;
			b[temp]--;
			b[mex]++;
			ans.push_back(N - 1);
			for (int j = 0; j <= N; j++) {
				if (b[j] > 0) {
					mex++;
				} else {
					mex = j;
					break;
				}
			}
			for (int j = 0; j < N; j++) {
				printf("%d ", a[j]);
			}
			printf("\n");
		}
		printf("!%d\n", mex);*/
		while (!done) {
			if (mex == N) {
				for (int j = 0; j <= N; j++) {
					if (a[j] != j) {
						b[a[j]]--;
						b[mex]++;
						mex = a[j];
						a[j] = N;
						ans.push_back(j);
						break;
					}
				}
			}
			int temp = a[mex];
			a[mex] = mex;
			ans.push_back(mex);
			b[temp]--;
			b[mex]++;
			if (b[temp] == 0 && temp < mex) {
				mex = temp;
			} else {
				for (int j = mex + 1; j <= N; j++) {
					if (b[j] == 0) {
						mex = j;
						break;
					}
				}
			}
			for (int j = 1; j < N; j++) {
				if (a[j - 1] > a[j]) break;
				if (j == N - 1) {
					done = true;
				}
			}
			/*for (int j = 0; j < N; j++) {
				printf("%d ", a[j]);
			}
			printf("\n");*/
			//printf("!%d %d\n", mex, b[mex]);
		}
		printf("%d\n", ans.size());
		for (auto x:ans) {
			printf("%d ", x + 1);
		}
		printf("\n");
	}
	return 0;
} 
