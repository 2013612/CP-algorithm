#include<bits/stdc++.h>
using namespace std;

int n, a[300006];
long long ans;

long long f(vector<int> v1, vector<int> v2) {
	long long res = 0;
	
	vector<int> v3 = v1, v4 = v2;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	int cur = 1e9;
	int l = v1.size() - 1;
	int r = v2.size() - 1;
	set<int> s1, s2;
	
	while (l >= 0 && r >= 0) {
		int k = min(v1[l], v2[r]);
		if (k == cur) {
			k--;
		}
		
		cur = k;
		
		if (cur == 0) {
			break;
		}
		
		s1.insert(cur);
		l--;
		r--;
	}
	
	{
		s2 = s1;
		
		for (int i = 0; i < v1.size() && s1.size(); i++) {
			auto x = s1.upper_bound(v3[i]);
			
			if (x == s1.begin()) {
				continue;
			}
			x--;
			
//			printf("!! %d %d %d\n", i, *x, v3[i]);
			s1.erase(x);

			res -= i;
		}
		
//		printf("res: %lld\n", res);
		
		for (int i = v2.size() - 1; i >= 0 && s2.size(); i--) {
			auto x = s2.upper_bound(v4[i]);
			
			if (x == s2.begin()) {
				continue;
			}
			x--;
			
			s2.erase(x);
			res += v1.size() + i;
		}
	}
	
	return res;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	vector<int> v1, v2;
	for (int i = 0; i < n / 2; i++) {
		v1.push_back(a[i]);
	}
	for (int i = n / 2; i < n; i++) {
		v2.push_back(a[i]);
	}
	
	ans = f(v1, v2);
	
	if (n & 1) {
		v1.clear();
		v2.clear();
		for (int i = 0; i < n / 2 + 1; i++) {
			v1.push_back(a[i]);
		}
		for (int i = n / 2 + 1; i < n; i++) {
			v2.push_back(a[i]);
		}
		
		ans = max(ans, f(v1, v2));
	}
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}