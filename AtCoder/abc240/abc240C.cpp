#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int n, x;
unordered_set<int> us[103];
int main() {
	scanf("%d %d", &n, &x);
	us[0].insert(0);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (auto q : us[i]) {
			us[i + 1].insert(q + a);
			us[i + 1].insert(q + b);
		}
	}
	if (us[n].count(x) == 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
