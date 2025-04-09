#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	string s1 = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') {
			s1 = s.substr(i);
			break;
		}
		if (i + 1 == s.length()) {
			printf("0\n");
			return;
		}
	}
	
	vector<int> v, v1;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '0') {
			if (v.empty()) {
				v.push_back(i);
			} else {
				v.push_back(i - v[0]);
			}
		} else {
			v1.push_back(i);
		}
	}
	
	if (v.empty()) {
		cout << s1 << endl;
		return;
	}
	
	v[0] = 0;
	
	vector<bool> t(v.size(), false);
	
	for (int i = 0; i < v1.size() && v1[i] + v.back() < s1.length(); i++) {
		vector<bool> t2;
		bool larger = false;
		for (int j = 0; j < v.size(); j++) {
			t2.push_back(s1[v1[i] + v[j]] == '1');
			if (!larger && t[j] && !t2[j]) {
				break;
			} else if (!t[j] && t2[j]) {
				larger = true;
			}
		}
		if (larger) {
			t = t2;
		}
	}
	
	
	string ans = "";
	for (int i = 0, j = 0; i < s1.length(); i++) {
		if (s1[i] == '1') {
			ans.push_back('1');
		} else {
			if (t[j]) {
				ans.push_back('1');
			} else {
				ans.push_back('0');
			}
			j++;
		}
	}
	
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}