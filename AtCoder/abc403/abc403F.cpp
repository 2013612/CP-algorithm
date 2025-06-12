#include<iostream>
#include<unordered_map>
using namespace std;

int n;
unordered_map<int, string> um, um2;

bool check(string &s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] =='(') {
			cnt++;
		} else if (s[i] == ')') {
			cnt--;
		} else if (s[i] == '+' && cnt == 0) {
			return false;
		}
	}
	
	return true;
}

string solve(int x) {
	if (um.count(x)) {
		return um[x];
	}
	
	string s = "", s2 = "";
	
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			string t1 = solve(i);
			if (!check(t1)) {
				if (um2[i].size() && um2[i].size() < t1.size() + 2) {
					t1 = um2[i];
				} else {
					t1 = "(" + t1 + ")";	
				}
			}
			
			string t2 = solve(x / i);
			if (!check(t2)) {
				if (um2[x / i].size() && um2[x / i].size() < t2.size() + 2) {
					t2 = um2[x / i];
				} else {
					t2 = "(" + t2 + ")";
				}
			}
			
			string t = t1 + "*" + t2;
			
			if (s.empty() || (t.size() < s.size())) {
				s = t;
			}
			
			if (s2.empty() || (t.size() < s2.size())) {
				s2 = t;
			}
		}
	}
	
	for (int i = 1; i <= x / 2; i++) {
		string t = solve(i) + "+" + solve(x - i);
		if (t.back() == '+') {
			t.pop_back();
		}
		
		if (s.empty() || (t.size() < s.size())) {
			s = t;
		}
	}
	
	
	um[x] = s;
	um2[x] = s2;
	
	return um[x];
}

int main() {
	scanf("%d", &n);
	
	um[1] = um2[1] = "1";
	um[11] = um2[1] = "11";
	um[111] = um2[1] = "111";
	um[1111] = um2[1] = "1111";
	
	cout << solve(n) << endl;
	
	return 0;
}