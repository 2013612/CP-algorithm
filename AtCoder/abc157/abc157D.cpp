#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, K, ans[200006], cou, group[200006], hate[200006][2], num[200006];
vector<int> fri[200006];

void dfs(int T) {
	for (auto x:fri[T]) {
		if (group[x] == 0) {
			group[x] = group[T];
			num[group[T]]++;
			dfs(x);
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	cou = 1;
	for (int i = 0; i < M; i++) {
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		fri[temp1].push_back(temp2);
		fri[temp2].push_back(temp1);
	}
	for (int i = 0; i < K; i++) {
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		hate[i][0] = temp1;
		hate[i][1] = temp2;
	}
	for (int i = 1; i <= N; i++) {
		if (group[i] == 0) {
			group[i] = cou;
			num[cou] = 1;
			cou++;
			dfs(i);
		}
	}
	//cout << cou << endl;
	for (int i = 1; i <= N; i++) {
		ans[i] = num[group[i]] - 1 - fri[i].size();
	}
	for (int i = 0; i < K; i++) {
		if (group[hate[i][0]] == group[hate[i][1]]) {
			ans[hate[i][0]]--;
			ans[hate[i][1]]--;
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
