#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, X, Y, a[3004][3004], ans[10005];
vector<int> graph[3004];
queue<int> q;

int main() {
	cin >> N >> X >> Y;
	for (int i = 2; i < N; i++) {
		graph[i].push_back(i - 1);
		graph[i].push_back(i + 1);
	}
	graph[1].push_back(2);
	graph[N].push_back(N - 1);
	graph[X].push_back(Y);
	graph[Y].push_back(X);
	for (int i = 1; i <= N; i++) {
		a[i][i] = 0;
		q.push(i);
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			for (int j = 0; j < graph[f].size(); j++) {
				if (a[i][graph[f][j]] == 0 && graph[f][j] != i) {
					a[i][graph[f][j]] = a[i][f] + 1;
					q.push(graph[f][j]);
				}
			}
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			ans[a[i][j]]++;
		}
	}
	for (int i = 1; i <= N - 1; i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
}
