#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/string>
using namespace std;
using namespace atcoder;

vector<int> sa;
string s;

bool f(int a, string t) {
	int n = sa.size();
	int m = t.size();
	for (int i = 0; a + i < n && i < m; i++) {
		if (s[a + i] != t[i]) {
			return s[a + i] < t[i];
		}
	}
	
	return n - a < m;
}

int solve(string s) {
	int lower = lower_bound(sa.begin(), sa.end(), s, f) - sa.begin();
	s.push_back(char('z' + 1));
	int upper = lower_bound(sa.begin(), sa.end(), s, f) - sa.begin();
	
	return upper - lower;
}

int main() {
	int q;
	cin >> s >> q;
	sa = suffix_array(s);
	for (int i = 0; i < q; i++) {
		string t;
		cin >> t;
		
		printf("%d\n", solve(t));
	}
	
	return 0;
}
