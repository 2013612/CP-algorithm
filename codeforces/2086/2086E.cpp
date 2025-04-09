#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

long long l, r, k;
vector<long long> v;

long long cal(long long n) {
	vector<long long> p;
	long long t = n;
	for (auto x: v) {
		p.push_back(t / x);
		t %= x;
	}
	
	map<long long, long long> m;
	long long cnt = 0;
	
	for (auto x: p) {
		map<long long, long long> temp;
		for (auto [u, v]: m) {
			for (int i = 0; i < 4; i++) {
				if (u + i <= k) {
					temp[u + i] += v;	
				}
			}
			
			if (u + 4 == k) {
				temp[u + 4] += v;
			}
		}
		
		for (int i = 0; i < x; i++) {
			if (cnt + i <= k) {
				temp[cnt + i]++;
			}
		}
		
		cnt += x;
		m = temp;
	}
	
	return m[k] + (cnt == k);
}

void solve() {
	scanf("%lld %lld %lld", &l, &r, &k);
	
	printf("%lld\n", cal(r) - cal(l - 1));
}

void init() {
	v.push_back(1);
	
	while (v.back() * 4 + 1 < 1e18) {
		v.push_back(v.back() * 4 + 1);
	}
	
	reverse(v.begin(), v.end());
}

int main() {
	init();
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}