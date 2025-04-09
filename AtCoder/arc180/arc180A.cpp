#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 1e9 + 7;

int n, a[200006], ans;
vector<int> v;

int main() {
	scanf("%d", &n);
	string s;
	cin >> s;
	string cur = s.substr(0, 1);
	ans = 1;
	
	for (int i = 1; i < n; i++) {
		cur.push_back(s[i]);
		int t = cur.size();
		
		if (cur[t - 1] == cur[t - 2]) {
			v.push_back(t / 2);
			cur = cur.substr(t - 1);
			continue;
		}
		
		if (i == n - 1) {
			v.push_back((t + 1) / 2);
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		ans = (1ll * ans * v[i]) % M;
	}
	
	printf("%d\n", ans);
	return 0;
}