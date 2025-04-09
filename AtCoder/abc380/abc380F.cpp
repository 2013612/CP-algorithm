#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
using namespace std;

int n, m, l;
multiset<int> a, b, c;
unordered_map<string, bool> um[2];

string f() {
	string t = "";
	for (auto x: a) {
		t += to_string(x);
		t.push_back(',');
	}
	t.push_back('|');
	for (auto x: b) {
		t += to_string(x);
		t.push_back(',');
	}
	t.push_back('|');
	for (auto x: c) {
		t += to_string(x);
		t.push_back(',');
	}
	return t;
}

bool dfs(int step) {
	string s = f();
	if (um[step].count(s)) {
		return um[step][s];
	}
	
	bool can = false;
	
	if (step == 0) {
		vector<int> v, v2;
		for (auto x: a) {
			if (v.empty() || v.back() != x) {
				v.push_back(x);
			}
		}
		for (auto x: c) {
			if (v2.empty() || v2.back() != x) {
				v2.push_back(x);
			}
		}
		for (auto x: v) {
			a.erase(a.find(x));
			c.insert(x);
			can = dfs(1 - step) || can;
			for (auto y: v2) {
				if (y >= x) {
					break;
				}
				
				a.insert(y);
				c.erase(c.find(y));
				
				can = dfs(1 - step) || can;
				
				a.erase(a.find(y));
				c.insert(y);
			}
			a.insert(x);
			c.erase(c.find(x));
		}
	} else {
		vector<int> v, v2;
		for (auto x: b) {
			if (v.empty() || v.back() != x) {
				v.push_back(x);
			}
		}
		for (auto x: c) {
			if (v2.empty() || v2.back() != x) {
				v2.push_back(x);
			}
		}
		for (auto x: v) {
			b.erase(b.find(x));
			c.insert(x);
			can = dfs(1 - step) || can;
			for (auto y: v2) {
				if (y >= x) {
					break;
				}
				
				b.insert(y);
				c.erase(c.find(y));
				
				can = dfs(1 - step) || can;
				
				b.erase(b.find(y));
				c.insert(y);
			}
			b.insert(x);
			c.erase(c.find(x));
		}
	}
	
	um[step][s] = !can;
	
	return um[step][s];
}


int main() {
	scanf("%d %d %d", &n, &m, &l);
	
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		a.insert(t);
	}
	
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		b.insert(t);
	}
	
	for (int i = 0; i < l; i++) {
		int t;
		scanf("%d", &t);
		c.insert(t);
	}
	
	if (!dfs(0)) {
		printf("Takahashi\n");
	} else {
		printf("Aoki\n");
	}
	
	return 0;
}