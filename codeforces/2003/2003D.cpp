#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, m, maxi;
vector<int> seq[200006], mex[200006];
vector<pair<int, int>> edge[200006];
set<int> s, s2;

int dfs(int node) {
//	printf("! node: %d\n", node);
	s.insert(node);
	int temp = node;
	
	if (node == 200005) {
		temp = -1;
	}
	
	for (int i = 0; i < edge[node].size(); i++) {
		if (!s.count(edge[node][i].first) && !s2.count(edge[node][i].second)) {
			s2.insert(edge[node][i].second);
			temp = max(temp, dfs(edge[node][i].first));
			s2.erase(edge[node][i].second);
		}
	}
	
	return temp;
}

void solve() {
	scanf("%d %d", &n, &m);
	maxi = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int l;
		scanf("%d", &l);
		seq[i].clear();
		seq[i].push_back(-1);
		mex[i].clear();
		for (int j = 0; j < l; j++) {
			int k;
			scanf("%d", &k);
			seq[i].push_back(k);
		}
		sort(seq[i].begin(), seq[i].end());
		seq[i].erase(unique(seq[i].begin(), seq[i].end()), seq[i].end());
	}
	
	for (int i = 0; i < n; i++) {
		bool temp = false;
		for (int j = 1; j < seq[i].size() && mex[i].size() < 2; j++) {
			if (seq[i][j] >= seq[i][j - 1] + 3) {
				mex[i].push_back(seq[i][j - 1] + 1);
				if (!temp) {
					mex[i].push_back(seq[i][j - 1] + 2);
				}
			} else if (seq[i][j] == seq[i][j - 1] + 2) {
				mex[i].push_back(seq[i][j - 1] + 1);
				temp = true;
			}
		}
		
		if (mex[i].size() == 0) {
			mex[i].push_back(seq[i].back() + 1);
			mex[i].push_back(seq[i].back() + 2);
		} else if (mex[i].size() == 1) {
			mex[i].push_back(seq[i].back() + 1);
		}
		
		maxi = max(maxi, mex[i].back());
		edge[mex[i][0]].push_back({mex[i][1], i});
		edge[200005].push_back({mex[i][0], i});
		s2.insert(mex[i][0]);
//		printf("# %d %d\n", mex[i][0], mex[i][1]);
	}
	
	for (int i = 0; i <= maxi; i++) {
		edge[i].clear();
	}
	edge[200005].clear();
	
	for (int i = 0; i < n; i++) {
		edge[mex[i][0]].push_back({mex[i][1], i});
		edge[200005].push_back({mex[i][0], i});
	}
	
	s.clear();
	s2.clear();
	int temp = dfs(200005);

//	printf("!!\n");
	for (int i = 0; i <= min(maxi, m); i++) {
		s.clear();
		s2.clear();
		int k = dfs(i);
		ans += max(k, temp);
//		printf("!%lld %d %d\n", ans, k, temp);
	}
//	ans = 1ll * maxi * min(m + 1, (maxi + 1));
	if (m > maxi) {
		ans += 1ll * (m + maxi + 1) * (m - maxi) / 2;
	}
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}