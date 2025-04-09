#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n, a[10000007];
unordered_map<int, int> um;
vector<int> p;

void sieve() {
	a[1] = 1;
	for (int i = 2; i <= 1e7 + 1; i++) {
		if (a[i] == 0) {
			a[i] = i;
			p.push_back(i);
		}
		
		for (auto x: p) {
			if (x > a[i] || x * i > 1e7 + 1) {
				break;
			}
			a[x * i] = x;
		}
	}
	
	for (int i = 0; i < p.size(); i++) {
		um[p[i]] = i + 1;
	}
	um[2] = 0;
	um[1] = 1;
	um[0] = 0;
}

void solve() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		k = um[a[k]];
		ans ^= k;
	}
	
	if (ans == 0) {
		printf("Bob\n");
	} else {
		printf("Alice\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	sieve();
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}