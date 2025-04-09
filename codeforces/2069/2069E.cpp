#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int n, a, b, ab, ba, ans;


void solve() {
	string s;
	cin >> s;
	n = s.length();
	vector<string> v, v2;
	unordered_map<string, int> um;
	
	scanf("%d %d %d %d", &a, &b, &ab, &ba);
	um["A"] = a;
	um["B"] = b;
	um["AB"] = ab;
	um["BA"] = ba;
	
	string t = "";
	for (int i = 0; i < n; i++) {
		if (!t.empty() && s[i] == t.back()) {
			if (t.size() == 1) {
				um[t]--;
			} else if (t.size() == 2) {
				if (um[t] > 0) {
					um[t]--;
				} else {
					um["A"]--;
					um["B"]--;
				}
			} else if (t.size() & 1) {
				v.push_back(t);
			} else {
				v2.push_back(t);
			}
			
			t.clear();
		}
		
		t.push_back(s[i]);
	}
	
	if (t.size() == 1) {
		um[t]--;
	} else if (t.size() == 2) {
		if (um[t] > 0) {
			um[t]--;
		} else {
			um["A"]--;
			um["B"]--;
		}
	} else if (t.size() & 1) {
		v.push_back(t);
	} else {
		v2.push_back(t);
	}
	
	bool valid = true;
	for (auto x: um) {
		if (x.second < 0) {
			valid = false;
		}
	}
	
	sort(v2.begin(), v2.end(), greater<string>());
	
	while (v2.size()) {
		string t = v2.back();
		
		int cnt = t.size() / 2;
		
		if (t[0] == 'A') {
			if (um["AB"] >= cnt) {
				um["AB"] -= cnt;
			} else {
				cnt -= um["AB"];
				um["AB"] = 0;
				
				um["A"]--;
				um["B"]--;
				cnt--;
				
				if (um["BA"] >= cnt) {
					um["BA"] -= cnt;
				} else {
					cnt -= um["BA"];
					um["BA"] = 0;
					
					um["A"] -= cnt;
					um["B"] -= cnt;
				}
			}
		} else {
			if (um["BA"] >= cnt) {
				um["BA"] -= cnt;
			} else {
				cnt -= um["BA"];
				um["BA"] = 0;
				
				um["A"]--;
				um["B"]--;
				cnt--;
				
				if (um["AB"] >= cnt) {
					um["AB"] -= cnt;
				} else {
					cnt -= um["AB"];
					um["AB"] = 0;
					
					um["A"] -= cnt;
					um["B"] -= cnt;
				}
			}
		}
		
		for (auto x: um) {
			if (x.second < 0) {
				
				valid = false;
			}
		}
		
		if (!valid) {
			break;
		} 
		v2.pop_back();
	}
	
	um["AB"] = um["AB"] + um["BA"];
	um["BA"] = 0;
	
	while (v.size()) {
		string t = v.back();
		
		int cnt = t.size() / 2;
		
		if (t[0] == 'A') {
			um["A"]--;
		} else {
			um["B"]--;
		}
		
		if (um["AB"] >= cnt) {
			um["AB"] -= cnt;
		} else {
			cnt -= um["AB"];
			um["AB"] = 0;
			
			um["A"] -= cnt;
			um["B"] -= cnt;
		}
		
		for (auto x: um) {
			if (x.second < 0) {
				valid = false;
			}
		}
		
		if (!valid) {
			break;
		} 
		v.pop_back();
	}
	
	if (!valid) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}