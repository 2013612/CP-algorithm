#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int n, k, a[200006], ans;

void solve() {
	scanf("%d %d", &n, &k);
	
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m[a[i]]++;
	}
	
	vector<int> v;
	for (auto x: m) {
		v.push_back(x.second);
	}
	
	sort(v.begin(), v.end(), greater<int>());
	
	while (v.size() > 1 && v.back() <= k) {
		k -= v.back();
		v.pop_back();
	}

	printf("%d\n", v.size());
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}