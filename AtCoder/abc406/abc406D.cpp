#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int h, w, n, q;
unordered_map<int, unordered_set<int>> um[2];

int main() {
	scanf("%d %d %d", &h, &w, &n);
	
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		
		um[0][x].insert(y);
		um[1][y].insert(x);
	}
	
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		int t, x;
		scanf("%d %d", &t, &x);
		t--;
		printf("%d\n", um[t][x].size());
		
		for (auto y: um[t][x]) {
			um[1 - t][y].erase(x);
		}
		um[t].erase(x);
	}
	
	return 0;
}