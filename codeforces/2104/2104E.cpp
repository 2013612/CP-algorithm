#include<bits/stdc++.h>
using namespace std;

int n, k, q, ans;
vector<int> v[30];
string s, t;
unordered_map<int, int> um;

int f(int ind) {
	if (um.count(ind)) {
		return um[ind];
	}
	
	int maxi = 0;
	for (int i = 0; i < k; i++) {
		int j = upper_bound(v[i].begin(), v[i].end(), ind) - v[i].begin();
		
		if (j == v[i].size()) {
			maxi = n;
		} else {
			maxi = max(maxi, v[i][j]);
		}
	}
	
	um[ind] = f(maxi) + 1;
	
	return um[ind];
}

int g() {
	int cur = -1;
	for (int i = 0; i < t.size(); i++) {
		int p = t[i] - 'a';
		int j = upper_bound(v[p].begin(), v[p].end(), cur) - v[p].begin();
		
		if (j == v[p].size()) {
			cur = n;
		} else {
			cur = v[p][j];
		}
	}
	
	return cur;
}

void solve() {
	scanf("%d %d", &n, &k);
	cin >> s;

	ans = 0;
	
	um[n] = 0;
	
	for (int i = 0; i < 26; i++) {
		v[i].clear();
	}
	
	for (int i = 0; i < n; i++) {
		v[s[i] - 'a'].push_back(i);
	}
	
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		cin >> t;
		
		printf("%d\n", f(g()));
	}
}

int main() {
	int t = 1;
//	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}