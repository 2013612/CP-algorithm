#include<bits/stdc++.h>
using namespace std;

const int N = 5810000;

int n, a[400005], ans;
vector<long long> pre;
bool nPrime[6000000];

void init() {
	pre.push_back(0);
	nPrime[0] = nPrime[1] = true;
	for (int i = 2; i <= N; i++) {
		if (!nPrime[i]) {
			for (int j = i + i; j <= N; j += i) {
				nPrime[j] = true;
			}
			
			pre.push_back(pre.back() + i);
		}
	}
}

void solve() {
	scanf("%d", &n);
	ans = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	sort(a, a + n);
	
	for (int i = 0; i < n; i++) {
		if (sum >= pre[n - i]) {
			printf("%d\n", i);
			break;
		}
		
		sum -= a[i];
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