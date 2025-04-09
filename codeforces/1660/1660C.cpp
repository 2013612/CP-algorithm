#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, t, ans;
string s;
vector<int> a[30];

int del(int pos) {
	if (pos >= s.size()) {
		return 0;
	} else if (pos == s.size() - 1) {
		return 1;
	}
	if (s[pos] == s[pos + 1]) {
		return del(pos + 2);
	}
	
	int k = s[pos] - 'a';
	
	int temp = upper_bound(a[k].begin(), a[k].end(), pos) - a[k].begin();
	
	if (temp == a[k].size()) {
		return 1 + del(pos + 1);
	}
	for (int i = pos + 1; i < a[k][temp]; i++) {
		int k2 = s[i] - 'a';
		int t2 = upper_bound(a[k2].begin(), a[k2].end(), i) - a[k2].begin();
		if (t2 == a[k2].size()) {
			continue;
		}
		if (a[k2][t2] < a[k][temp]) {
			return i - pos + del(i);
		}
	}
	return a[k][temp] - pos - 1 + del(a[k][temp] + 1);
}

void solve() {
	ans = 0;
	cin >> s;
	for (int i = 0; i < 30; i++) {
		a[i].clear();
	}
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 'a'].push_back(i);
	}
	ans = del(0);
	printf("%d\n", ans);
}

int main() {
	scanf("%d", &t);
	while (t-- > 0)  {
		solve();
	}
	return 0;
}
