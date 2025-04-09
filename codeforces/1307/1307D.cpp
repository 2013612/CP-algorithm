#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, M, K, a[200006], ans, b[200006];
vector<int> graph[200006];

void bfs(int x) {
	vector pro;
	pro.push_back(x);
	for (int i = 0; i < N; i++) {
		for (auto t:graph[pro[i]]) {
			if (t != 1 && b[t] == 0) {
				b[t] = b[pro[i]] + 1;
				pro.push_back(t);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}
	b[1] = 0;
	if (K == 2) {
		graph[a[0]].push_back(a[1]);
		graph[a[1]].push_back(a[0]);
		bfs(1);
		printf("%d\n", b[N]);
		return 0;
	}
	sort(a, a + N);
	bfs(1);
	return 0;
}
