#include<iostream>
#include<vector>
#include<set>
using namespace std;

int step[200006];
vector<int> e[200006];

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	set<int> s;
	for (int i = 1; i <= n; i++) {
		e[i].clear();
		e[i].push_back(i + 1);
		s.insert(i);
		step[i] = 1e9;
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
	}
	
	step[1] = 0;
	set<int> ans;
	
	for (int i = 1; i < n; i++) {
		step[i] = min(step[i], i - 1);
		
		for (int j = 0; j < e[i].size(); j++) {
			step[e[i][j]] = min(step[e[i][j]], step[i] + 1);
			auto low = s.lower_bound(i + 1);
			auto high = s.upper_bound(e[i][j] - step[e[i][j]] - 1);
			if (low != s.end() && (high == s.end() || (*low) < (*high))) {
				s.erase(low, high);
			}
		}
	}
	
	string temp = "";
	for (int i = 1; i < n; i++) {
		if (s.count(i)) {
			temp.push_back('1');
		} else {
			temp.push_back('0');
		}
	}
	
	cout << temp << endl;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}