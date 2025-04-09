#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int T, N, M, a[1000007];
int main() {
	freopen("runway_input.txt", "r", stdin);
	freopen("runway_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d", &N, &M);
		int ans = 0;
		unordered_map<int, int> unused[2], used[2];
		for (int j = 0; j < M; j++) {
			int temp;
			scanf("%d", &temp);
			unused[0][temp]++;
		}
		for (int j = 0; j < N; j++) {
			unordered_map<int, int> waiting;
			for (int k = 0; k < M; k++) {
				int temp;
				scanf("%d", &temp);
				if (used[j % 2].count(temp)) {
					used[j % 2][temp]--;
					used[1 - j % 2][temp]++;
					if (used[j % 2][temp] == 0) {
						used[j % 2].erase(temp);
					}
				} else if (unused[j % 2].count(temp)) {
					unused[j % 2][temp]--;
					unused[1 - j % 2][temp]++;
					if (unused[j % 2][temp] == 0) {
						unused[j % 2].erase(temp);
					}
				} else {
					waiting[temp]++;
				}
			}
			for (auto x:waiting) {
				used[1 - j % 2][x.first] += x.second;
			}
			for (auto x:used[j % 2]) {
				ans += x.second;
			}
			used[j % 2].clear();
			unused[j % 2].clear();
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
