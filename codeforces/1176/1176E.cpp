#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int T, M, N, a[200006];
vector<int> edge[200006], ans;

void dfs(int x) {
	if (a[x] == 1) {
		vector<int> temp;
		for (auto y: edge[x]) {
			//printf("$%d %d %d\n", x, y, a[y]);
			if (a[y] == 0) {
				a[y] = -1;
				temp.push_back(y);
			}
		}
		for (auto y: temp) {
			//printf("!%d %d\n", x, y);
			dfs(y);
		}
	} else {
		for (auto y: edge[x]) {
			if (a[y] == 0) {
				a[y] = 1;
				ans.push_back(y);
				dfs(y);
			}
		}
	}
	//printf("@%d %d\n", x, a[x]);
}

int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		for (int j = 0; j < M; j++) {
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			edge[temp1].push_back(temp2);
			edge[temp2].push_back(temp1);
		}
		for (int j = 1; j <= N; j++) {
			a[j] = 1;
			ans.push_back(j);
			dfs(j);
			for (int k = 1; k <= N; k++) {
				a[k] = 0;
			}
			if (ans.size() <= N/2) {
				break;
			}
			ans.clear();
		}
		printf("%d\n", ans.size());
		for (auto x:ans) {
			printf("%d ", x);
		}
		printf("\n");
		for (int j = 1; j <= N; j++) {
			edge[j].clear();
		}
		ans.clear();
	}
	return 0;
}
