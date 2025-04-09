#include<iostream>
using namespace std;

const int M = 1e9 + 7;

int n;
string s;

void solve() {
	scanf("%d", &n);
	cin >> s;
	long long ans = 0;
	long long sum = 0;
	int cnt = 0;
	int dup = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) {
			sum += cnt;
			sum += dup;
			
			cnt += i + 1;
		} else {
			dup += i + 1;
			sum += cnt;
		}
		
		ans += sum;
		
		sum %= M;
		ans %= M;
		cnt %= M;
		dup %= M;
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