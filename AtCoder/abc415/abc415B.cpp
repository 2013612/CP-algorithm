#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;
string s;

int main() {
	cin >> s;
	n = s.size();
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == '#') {
			v.push_back(i + 1);
		}
		
		if (v.size() == 2) {
			printf("%d,%d\n", v[0], v[1]);
			v.clear();
		}
	}
	
	return 0;
}