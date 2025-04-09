#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, m;
set<pair<int, int>> s;

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		
		if (u > v) {
			swap(u, v);
		}
		
		if (u != v) {
			s.insert({u, v});
		}
	}
	
	printf("%d\n", m - s.size());
	return 0;
}