#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int t, n, ans;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		unordered_set<int> us;
		for (int i = 0; i < n; i++) {
			int k;
			scanf("%d", &k);
			us.insert(k);
		}
		if (us.count(1) == 0) {
			printf("YES\n");
		} else if (us.count(0) == 1) {
			printf("NO\n");
		} else {
			bool can = true;
			for (auto x:us) {
				if (us.count(x + 1)) {
					can = false;
					break;
				}
			}
			if (can) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	
	return 0;
}
