#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int n, ans, a[200006];
vector<int> v[200006];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		v[i].clear();
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
	}
	
	for (int i = 1; i <= n; i++) {
		if (v[i].empty()) {
			printf("0 ");
			continue;
		}
		int ans = 1;
		int cur = v[i][0];
		int temp = -1;
		for (int j = 1; j < v[i].size(); j++) {
			if ((v[i][j] - cur) & 1) {
				ans++;
				cur = v[i][j];
			} else {
				if (temp == -1) {
					temp = j;
				}
			}
		}
		int len = 1;
		cur = v[i][temp];
		for (int j = temp; j < v[i].size(); j++) {
			if ((v[i][j] - cur) & 1) {
				len++;
				cur = v[i][j];
			}
		}
		printf("%d ", max(ans, len));
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}