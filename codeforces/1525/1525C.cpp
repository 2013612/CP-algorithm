#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int T, N, M, a[300006], ans[300006];
pair<int, string> input[300006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		vector<int> ro, re, lo, le;
		int pos[300006];
		for (int j = 0; j <= M; j++) {
			ans[j] = 0;
		}
		for (int j = 0; j < N; j++) {
			scanf("%d", &input[j].first);
			pos[j] = input[j].first;
		}
		for (int j = 0; j < N; j++) {
			cin >> input[j].second;
		}
		sort(input, input + N);
		for (int j = 0; j < N; j++) {
			a[j] = input[j].first;
		}
		for (int j = 0; j < N; j++) {
			string s = input[j].second;
			if (s == "R") {
				if (a[j] & 1) {
					ro.push_back(a[j]);
				} else {
					re.push_back(a[j]);
				}
			} else {
				if (a[j] & 1) {
					if (ro.size()) {
						ans[ro.back()] = (a[j] - ro.back()) / 2;
						ans[a[j]] = (a[j] - ro.back()) / 2;
						ro.pop_back();
					} else {
						lo.push_back(a[j]);
					}
				} else {
					if (re.size()) {
						ans[re.back()] = (a[j] - re.back()) / 2;
						ans[a[j]] = (a[j] - re.back()) / 2;
						re.pop_back();
					} else {
						le.push_back(a[j]);
					}
				}
			}
		}
		//cout << ans[3] << endl;
		for (int j = re.size() - 1; j >= 1; j -= 2) {
			ans[re[j]] = ans[re[j - 1]] = M - (re[j] + re[j - 1]) / 2;
			re.pop_back();
			re.pop_back();
		}
		for (int j = ro.size() - 1; j >= 1; j -= 2) {
			ans[ro[j]] = ans[ro[j - 1]] = M - (ro[j] + ro[j - 1]) / 2;
			ro.pop_back();
			ro.pop_back();
		}
		for (int j = 0; j + 1 < le.size(); j += 2) {
			ans[le[j]] = ans[le[j + 1]] = (le[j + 1] + le[j]) / 2;
		}
		for (int j = 0; j + 1 < lo.size(); j += 2) {
			ans[lo[j]] = ans[lo[j + 1]] = (lo[j + 1] + lo[j]) / 2;
		}
		if (le.size() & 1) {
			le = vector<int>(1, le.back());
		} else {
			le.clear();
		}
		if (lo.size() & 1) {
			lo = vector<int>(1, lo.back());
		} else {
			lo.clear();
		}
		//cout << ans[pos[1]] << endl;
		if (M & 1) {
			if (lo.size() && re.size()) {
				ans[lo[0]] = ans[re[0]] = (2 * M + lo[0] - re[0]) / 2;
				lo.pop_back();
				re.pop_back();
			}
			if (le.size() && ro.size()) {
				ans[le[0]] = ans[ro[0]] = (2 * M + le[0] - ro[0]) / 2;
				le.pop_back();
				ro.pop_back();
			}
		} else {
			if (lo.size() && ro.size()) {
				ans[lo[0]] = ans[ro[0]] = (2 * M + lo[0] - ro[0]) / 2;
				lo.pop_back();
				ro.pop_back();
			}
			if (le.size() && re.size()) {
				ans[le[0]] = ans[re[0]] = (2 * M + le[0] - re[0]) / 2;
				le.pop_back();
				re.pop_back();
			}
		}
		for (int j = 0; j < N; j++) {
			if (ans[pos[j]] != 0) {
				printf("%d ", ans[pos[j]]);
			} else {
				printf("-1 ");
			}
		}
		printf("\n");
	}
	return 0;
}
