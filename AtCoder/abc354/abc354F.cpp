#include<iostream>
#include<vector>
using namespace std;

int t, n, a[200006];
bool ans[200006];

void solve() {
	scanf("%d", &n);
	vector<int> v;
	vector<vector<pair<int, int>>> vd;
	
	for (int i = 0; i < n; i++) {
		ans[i] = false;
		scanf("%d", &a[i]);
		
		int ind = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		if (ind == v.size()) {
			v.push_back(a[i]);
			vector<pair<int, int>> temp;
			temp.push_back({a[i], i});
			vd.push_back(temp);
		} else {
			v[ind] = a[i];
			vd[ind].push_back({a[i], i});
		}
	}
	
	int cnt = 0;
	for (int i = vd.size() - 1; i >= 0; i--) {
		if (i == vd.size() - 1) {
			for (int j = 0; j < vd[i].size(); j++) {
				ans[vd[i][j].second] = true;
				cnt++;
			}
			continue;
		}
		int j = 0, k = 0;
		while (j < vd[i].size() && k < vd[i + 1].size()) {
			if (!ans[vd[i + 1][k].second]) {
				k++;
				continue;
			}
			if (vd[i][j].first < vd[i + 1][k].first) {
				if (vd[i][j].second < vd[i + 1][k].second) {
					ans[vd[i][j].second] = true;
					j++;
					cnt++;
				} else {
					k++;
				}
			} else {
				ans[vd[i][j].second] = false;
				j++;
			}
		}
	}
	
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) {
		if (ans[i]) {
			cnt--;
			printf("%d%c", i + 1, cnt == 0 ? '\n': ' ');
		}
	}
}

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
}