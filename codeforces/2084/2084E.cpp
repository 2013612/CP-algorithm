#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int n, m, k;
vector<int> v;
long long ans, fac[5004];

long long power(int a, long long x) {
	if (x == 0) {
		return 1;
	}
	
	if (x & 1) {
		return 1ll * a * power(a, x - 1) % M;
	} else {
		long long t = power(a, x / 2);
		return t * t % M;
	}
}

long long inv(int a) {
	return power(a, M - 2);
}

long long perm(int n, int r) {
	if (n == 0) {
		return 0;
	}
	
	return fac[n] * inv(fac[n - r]) % M;
}

void solve() {
	scanf("%d", &n);
	v.resize(n);
	
	set<int> s;
	vector<int> s_v;
	
	for (int i = 0; i < n; i++) {
		s.insert(i);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		
		if (v[i] != -1) {
			s.erase(v[i]);
		}
	}
	
	ans = 0;
	
	int free = s.size();
	
	for (auto x: s) {
		s_v.push_back(x);
	}
	
	for (int i = 0; i < n; i++) {
		set<int> p = s;
		set<int> q;
		
		for (int j = 0; j <= n; j++) {
			q.insert(j);
		}
		vector<int> temp;
		
		int cnt = 0;
		for (int j = i; j < n; j++) {
			printf("ind: %d %d\n", i, j);
			if (v[j] == -1) {
				temp.push_back(*(p.begin()));
				q.erase(*(p.begin()));
				p.erase(p.begin());
				cnt++;
			} else {
				q.erase(v[j]);
			}
			
			for (int k = 1; k <= (*(q.begin())); k++) {
				int need = upper_bound(temp.begin(), temp.end(), k - 1) - temp.begin();
				
				int left = upper_bound(s_v.begin(), s_v.end(), k) - s_v.begin();
				left = free - left;
				
				printf("mex: %d need: %d perm: %d %d %d\n", k, need, left, cnt - need, perm(left, cnt - need));
				
				long long sum = 1ll * k * fac[need] % M;
				
				if (cnt - need > 0) {
					sum *= perm(left, cnt - need);
				}
				
				if (left - (cnt - need) < 0) {
					sum = 0;
				}
				
				sum %= M;
				
				ans += sum;
				ans %= M;
			}
			
//			printf("mex: %d fac: %d\n", *(q.begin()), fac[cnt]);
//			ans += 1ll * (*(q.begin())) * fac[cnt] % M;
//			ans %= M;
		}
	}
	
	printf("%lld\n", ans);
}

void init() {
	fac[0] = 1;
	for (int i = 1; i <= 5000; i++) {
		fac[i] = fac[i - 1] * i % M;
	}
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