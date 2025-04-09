#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int n, a[200006][2];

void solve() {
	scanf("%d", &n);
	vector<int> v;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
		if(a[i][0] == a[i][1]) {
			if (!m.count(a[i][0])) {
				v.push_back(a[i][0]);
			}
			m[a[i][0]]++;
		}
	}
	
	sort(v.begin(), v.end());
	
	string ans;
	
	for (int i = 0; i < n; i++) {
		if (a[i][0] == a[i][1]) {
			if (m[a[i][0]] == 1) {
				ans.push_back('1');
			} else {
				ans.push_back('0');
			}
		} else {
			int l = lower_bound(v.begin(), v.end(), a[i][0]) - v.begin();
			int r = lower_bound(v.begin(), v.end(), a[i][1]) - v.begin();
			if (r - l == a[i][1] - a[i][0] && l >= 0 && r < v.size() && v[l] == a[i][0] && v[r] == a[i][1]) {
				ans.push_back('0');
			} else {
				ans.push_back('1');
			}
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