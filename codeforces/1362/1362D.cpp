#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, M, now[500005];
vector<int> link[500005], t[500005], ans;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		link[a].push_back(b);
		link[b].push_back(a);
	}
	int maxi = 0;
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		t[temp].push_back(i);
		maxi = max(maxi, temp);
	}
	bool success = true;
	for (int i = 1; i <= maxi; i++) {
		for (auto x:t[i]) {
			if (now[x] != i - 1) {
				success = false;
			}
			for (auto y:link[x]) {
				if (now[y] == i - 1) {
					now[y]++;
				}
			}
			ans.push_back(x);
		}
	}
	if (!success) {
		printf("-1\n");
	} else {
		for (auto x:ans) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}
