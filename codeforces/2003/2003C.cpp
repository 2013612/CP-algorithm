#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[30], ans;
vector<pair<int, int>> v;

void solve() {
	scanf("%d", &n);
	string s;
	cin >> s;
	
	string ans = string(n, ' ');
	
	for (int i = 0; i < 26; i++) {
		a[i] = 0;
	}
	
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 'a']++;
	}
	v.clear();
	for (int i = 0; i < 26; i++) {
		if (a[i] > 0) {
			v.push_back({a[i], i});
		}
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	
	int j = 0;
	for (int i = 0; i < n; i += 2) {
		ans[i] = (char) ('a' + v[j].second);
		v[j].first--;
		if (v[j].first == 0) {
			j++;
		}
	}
	for (int i = 1; i < n; i += 2) {
		ans[i] = (char) ('a' + v[j].second);
		v[j].first--;
		if (v[j].first == 0) {
			j++;
		}
	}
	
	cout << ans << endl;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}