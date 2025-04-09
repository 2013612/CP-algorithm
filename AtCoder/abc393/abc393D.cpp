#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
string s;
vector<long long> v, pre;
long long ans = 1e18;

int main() {
	scanf("%d", &n);
	
	cin >> s;
	
	pre.push_back(0);
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			v.push_back(i);
			pre.push_back(pre.back() + i);
		}
	}
	
	int m = v.size();
	
	ans = pre.back() - pre[1] - v[0] * (m - 1);
	ans -= 1ll * m * (m - 1) / 2;
	
	for (int i = 1; i < m; i++) {
		long long t1 = 1ll * (v[i] - 1) * i - pre[i];
		t1 -= 1ll * i * (i - 1) / 2;
		long long t2 = pre.back() - pre[i + 1] - v[i] * (m - i - 1);
		t2 -= 1ll * (m - i - 1) * (m - i) / 2;
		
		ans = min(ans, t1 + t2);
	}
	
	printf("%lld\n", ans);
	return 0;
}