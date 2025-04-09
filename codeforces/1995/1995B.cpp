#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

long long n, m, a[200006], ans;
map<long long, long long> mp;

void solve() {
	scanf("%lld %lld", &n, &m);
	ans = 0;
	mp.clear();
	
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		long long temp;
		scanf("%lld", &temp);
		mp[a[i]] += temp;
	}
	
	for (auto it = mp.begin(); it != mp.end(); it++) {
		long long key = it->first;
		long long v = it->second;
		long long cnt = min(m / key, v);
		ans = max(ans, cnt * key);
	}
	
	auto last = mp.end();
	last--;
	
	for (auto it = mp.begin(); it != last; it++) {
		auto temp = it;
		temp++;
		long long key1 = it->first;
		long long key2 = temp->first;
		long long v1 = it->second;
		long long v2 = temp->second;
		
		if (key2 - key1 != 1) {
			continue;
		}
		
		if (key1 * v1 + key2 * v2 <= m) {
			ans = max(ans, key1 * v1 + key2 * v2);
		} else {
			if (key1 * v1 > m) {
				v1 = m / key1;
			}
			long long left = m - key1 * v1;
			long long cnt = min(v2, left / key2);
			left -= key2 * cnt;
			v2 -= cnt;
			left -= min(v1, v2);
			left = max(left, 0ll);
			ans = max(ans, m - left);
		}
		
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