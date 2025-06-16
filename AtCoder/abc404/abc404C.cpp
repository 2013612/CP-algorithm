#include<iostream>
#include<vector>
using namespace std;

int n, m, ans = 1e9;
bool can = true;
vector<int> g[200005];

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	if (n != m) {
		printf("No\n");
		return 0;
	}
	
	int prev = -1, cur = 1;
	
	for (int i = 0; i < n; i++) {
		if (g[cur].size() != 2) {
			can = false;
			break;
		}
		
		if (g[cur][0] == prev) {
			prev = cur;
			cur = g[cur][1];
		} else {
			prev = cur;
			cur = g[cur][0];
		}
		
		if (i != n - 1 && cur == 1) {
			can = false;
			break;
		}
	}
	
	if (can && cur == 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}