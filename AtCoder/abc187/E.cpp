#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int N, Q, index, n, parent[200006];
long long t[400006];
bool arr[200006];
vector<int> graph[200006];
pair<int, int> range[200006], edge[200006];

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

void push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}

void dfs(int node) {
	arr[node] = true;
	range[node].first = index - N;
	index++;
	for (auto x: graph[node]) {
		if (!arr[x]) {
			parent[x] = node;
			dfs(x);
		}
	}
	range[node].second = index - N;
}

int main() {
	scanf("%d", &N);
	index = N;
	n = N;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &edge[i].first, &edge[i].second);
		graph[edge[i].first].push_back(edge[i].second);
		graph[edge[i].second].push_back(edge[i].first);
	}
	dfs(1);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int T, e, x;
		scanf("%d %d %d", &T, &e, &x);
		e = e - 1;
		int A, B;
		if (T == 1) {
			A = edge[e].first;
			B = edge[e].second;
		} else {
			A = edge[e].second;
			B = edge[e].first;
		}
		if (parent[A] == B) {
			modify(range[A].first, range[A].second, x);
		} else {
			modify(range[1].first, range[1].second, x);
			modify(range[B].first, range[B].second, -x);
		}
	}
	push();
	for (int i = 1; i <= N; i++) {
		printf("%lld\n", t[range[i].first + N]);
	}
	return 0;
}
