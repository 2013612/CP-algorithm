#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct Train {
	int s, t, a, b, ind;
};

bool f(Train a, Train b) {
	return a.s < b.s;
}

bool g(Train a, int b) {
	return a.s < b;
}

int n, m, x[200006], min_start_time[200006];
bool start[200006], visited[200006];
vector<Train> v[200006];
Train train[200006];
vector<int> edge[200006];

void dfs(int node) {
	for (int i = 0; i < edge[node].size(); i++) {
		if (!visited[edge[node][i]]) {
			dfs(edge[node][i]);
		}
		
		
		Train temp = train[edge[node][i]];
//		printf("! %d %d %d %d %d\n", edge[node][i], node, min_start_time[edge[node][i]], temp.t, temp.s);
		int new_time = min_start_time[edge[node][i]];
		
		if (train[node].a != temp.a) {
			new_time += temp.t - temp.s;
		}
		
		min_start_time[node] = max(min_start_time[node], new_time);
	}
	visited[node] = true;
}

int main() {
	scanf("%d %d %d", &n, &m, &x[0]);
	
	for (int i = 0; i < m; i++) {
		int a, b, s, t;
		scanf("%d %d %d %d", &a, &b, &s, &t);
		a--;
		b--;
		
		if (i == 0) {
			a = n;
		}
		
		Train temp;
		temp.a = a;
		temp.b = b;
		temp.s = s;
		temp.t = t;
		temp.ind = i;
		train[i] = temp;
		v[a].push_back(temp);
		min_start_time[i] = s;
		start[i] = true;
	}
	n++;
	
	min_start_time[0] += x[0];
	
	for (int i = 0; i < n; i++) {
		sort(v[i].begin(), v[i].end(), f);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			Train k = v[i][j];
			int pos = lower_bound(v[k.b].begin(), v[k.b].end(), k.t, g) - v[k.b].begin();
			
			if (pos < v[k.b].size()) {
				edge[v[k.b][pos].ind].push_back(k.ind);
				start[k.ind] = false;
			}
			
			if (j + 1 < v[i].size()) {
				edge[v[i][j + 1].ind].push_back(k.ind);
				start[k.ind] = false;
			}
			
//			printf("& %d %d\n", v[k.b][pos].ind, k.ind);
			
		}
	}
	
	for (int i = 0; i < m; i++) {
//		printf("^ %d %d\n", i, start[i]);
		if (start[i]) {
			dfs(i);
		}
	}
	
	for (int i = 1; i < m; i++) {
		printf("%d ", min_start_time[i] - train[i].s);
	}
	printf("\n");
	return 0;
}