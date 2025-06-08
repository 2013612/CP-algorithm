#include<bits/stdc++.h>
using namespace std;

int n, q;
string s;
unordered_map<string, set<int>> um;

void solve() {
	scanf("%d %d", &n, &q);
	
	um.clear();
	cin >> s;
	
	for (int i = 0; i < q; i++) {
		string a, b;
		cin >> a >> b;
		
		um[a + b].insert(i);
	}
	
//	for (auto [x, y]: um) {
//		cout << x << endl;
//		for (auto p: y) {
//			printf("%d ", p);
//		}
//		printf("\n");
//	}
	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'c') {
			if (um["ca"].size()) {
				s[i] = 'a';
				um["ca"].erase(um["ca"].begin());
				continue;
			} 
			if (um["cb"].size()) {
				int k = *um["cb"].begin();
				s[i] = 'b';
				um["cb"].erase(um["cb"].begin());
					
				auto x = um["ba"].upper_bound(k);
				if (x != um["ba"].end()) {
					s[i] = 'a';
					um["ba"].erase(x);
				}
				
				continue;
			}
		} else if (s[i] == 'b') {
			if (um["ba"].size()) {
				s[i] = 'a';
				um["ba"].erase(um["ba"].begin());
				continue;
			}
			
			if (um["bc"].size()) {
				auto x = um["bc"].begin();
				auto y = um["ca"].upper_bound(*x);
				
				if (y != um["ca"].end()) {
					s[i] = 'a';
					um["bc"].erase(x);
					um["ca"].erase(y);
				}
			}
		}
		
//		cout << s << endl;
	}
	
	cout << s << endl;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}