#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<pair>
using namespace std;

int N, M, con, num;
vector<pair<int,int>> road[100006];
vector<int> ans;
int color[100006];

void dfs(int x) {
	if (color[x] == 2) {
		return;
	} else if (color[x] == 1) {
		
	} else {
		for (int i = 0; i < road[x].size(); i++) {
			dfs(road[x][i].first);
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int temp[3]
		scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);
		road[temp[0]].push_back(temp[1], temp[2]);
	}
	for (int i = 0; i < N; i++) {
		if (color[i] == 0) {
			dfs(i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
