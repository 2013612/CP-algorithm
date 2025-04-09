#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, k;

void solve() {
	scanf("%d %d", &n, &k);
	int skip = n * n - 1 - k;
	vector<pii> ans;
	int step = n;
	int next = 0;
	int add = 0;
	while (skip != 0 && step > 1) {
		for (int i = next; i < 4; i++) {
			int jump = step * 4 - 5 - 2 * i - 1;
			if (jump == 0) {
				break;
			}
			if (skip >= jump) {
				int cur = add + step * i + 2 - i;
				ans.push_back({cur, cur + jump + 1});
				skip -= jump;
				break;
			}
			next = (next + 1) % 4;
		}
		add += step / 2 * 8;
		step -= 2;
	}
	
	if (skip != 0) {
		printf("IMPOSSIBLE\n");
	} else {
		printf("%d\n", ans.size());
		for (auto [a, b] : ans) {
			printf("%d %d\n", a, b);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}