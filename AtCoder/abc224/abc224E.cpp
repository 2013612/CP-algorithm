#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int N, H, W, ans;
map<int, vector<int>> h[200006], w[200006];
map<int, int> h_max[200006], w_max[200006];
map<pii, int> dp, pts;
pii P[200006];

int solve(pii pt) {
	if (dp.count(pt) == 1) {
		return dp[pt];
	}
	int value = pts[pt];
	int k = 0;
	auto temp = h[pt.first].upper_bound(value);
	if (temp != h[pt.first].end()) {
		vector<int> v = temp->second;
		if (h_max[pt.first].count(temp->first) == 0) {
			int pp = 0;
			for (auto x:v) {
				pp = max(pp, 1 + solve({pt.first, x}));
			}
			h_max[pt.first][temp->first] = pp;
		} 
		k = max(k, h_max[pt.first][temp->first]);
	}
	auto temp2 = w[pt.second].upper_bound(value);
	if (temp2 != w[pt.second].end()) {
		vector<int> v = temp2->second;
		if (w_max[pt.second].count(temp2->first) == 0) {
			int pp = 0;
			for (auto x:v) {
				pp = max(pp, 1 + solve({x, pt.second}));
			}
			w_max[pt.second][temp2->first] = pp;
		}
		k = max(k, w_max[pt.second][temp2->first]);
	}
	dp[pt] = k;
	return k;
}

int main() {
	scanf("%d %d %d", &H, &W, &N);
	for (int i = 0; i < N; i++) {
		int r, c, a;
		scanf("%d %d %d", &r, &c, &a);
		h[r][a].push_back(c);
		w[c][a].push_back(r);
		pts[{r, c}] = a;
		P[i] = {r, c};
	}
	for (int i = 0; i < N; i++) {
		solve(P[i]);
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", dp[P[i]]);
	}
	return 0;
}
