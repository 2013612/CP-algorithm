#include<iostream>
#include<unordered_set>
using namespace std;

int n, m, q;
unordered_set<int> us[200005], all;

int main() {
	scanf("%d %d %d", &n, &m, &q);
	
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		
		if (t == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			us[x].insert(y);
		} else if (t == 2) {
			int x;
			scanf("%d", &x);
			all.insert(x);
		} else {
			int x, y;
			scanf("%d %d", &x, &y);
			
			if (all.count(x) || us[x].count(y)) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
	
	return 0;
}