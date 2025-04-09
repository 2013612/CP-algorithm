#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int T, N, du[800006], parent[800006], level[800006], size[800006];
unordered_map<int, unordered_map<int, bool>> um;
unordered_map<int, vector<int>> fre;

int find(int k) {
	if (du[k] == k) {
		return k;
	}
	return du[k] = find(du[k]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        du[b] = a;
        if (size[a] == size[b])
            size[a]++;
    }
}

void dfs(int node) {
	for (auto x:um[node]) {
		if (x.first != parent[node]) {
			parent[x.first] = node;
			level[x.first] = level[node] + 1;
			dfs(x.first);
		}
	}
}

void lca(int a, int b) {
	while (find(a) != find(b)) {
		if (level[a] < level[b]) {
			um[b][parent[b]] = true;
			um[parent[b]][b] = true;
			join(b, parent[b]);
			b = parent[b];
		} else if (level[b] < level[a]) {
			um[a][parent[a]] = true;
			um[parent[a]][a] = true;
			join(a, parent[a]);
			a = parent[a];
		} else {
			um[b][parent[b]] = true;
			um[parent[b]][b] = true;
			join(b, parent[b]);
			um[a][parent[a]] = true;
			um[parent[a]][a] = true;
			join(a, parent[a]);
			b = parent[b];
			a = parent[a];
		}
	}
}

int main() {
	freopen("chainblock_input.txt", "r", stdin);
	freopen("chainblock_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		int ans = 0;
		fre.clear();
		um.clear();
		for (int j = 0; j < N - 1; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			um[a][b] = false;
			um[b][a] = false;
		}
		for (int j = 1; j <= N; j++) {
			du[j] = j;
			size[j] = 1;
			parent[j] = 0;
			level[j] = 0;
			int temp;
			scanf("%d", &temp);
			fre[temp].push_back(j);
		}
		dfs(1);
		for (auto x:fre) {
			for (int j = 1; j < x.second.size(); j++) {
				//printf("@ %d %d\n", x.second[0], x.second[j]);
				lca(x.second[0], x.second[j]);
			}
		}
		for (auto x:um) {
			for (auto y:x.second) {
				if (!y.second) {
					//printf("! %d %d\n", x.first, y.first);
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", i, ans / 2);
	}
	return 0;
}
