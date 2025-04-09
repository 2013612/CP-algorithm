#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int N, M1, M2;
 
class DisjointSet{ 
public:
    vector<int> parent;
 
    DisjointSet(int n): parent(n) { for(int i=0; i<n; i++) parent[i] = i; }
 
    void join(int a, int b) { parent[find(b)] = find(a); }
 
    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }
 
    bool check(int a, int b){ return find(a) == find(b); }
    
    void print() {
    	for (auto x:parent) {
    		printf("%d ", x);
		}
		printf("\n");
	}
};
 
int main() {
	scanf("%d %d %d", &N, &M1, &M2);
	DisjointSet a = DisjointSet(N);
	DisjointSet b = DisjointSet(N);
	for (int i = 0; i < M1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a.join(u - 1, v - 1);
	}
	for (int i = 0; i < M2; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		b.join(u - 1, v - 1);
	}
	vector<pair<int, int>> edge;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!a.check(i, j) && !b.check(i, j)) {
				a.join(i, j);
				b.join(i, j);
				edge.push_back({i + 1, j + 1});
			}
		}
	}
	printf("%d\n", edge.size());
	for (auto x:edge) {
		printf("%d %d\n", x.first, x.second);
	}
	return 0;
}

