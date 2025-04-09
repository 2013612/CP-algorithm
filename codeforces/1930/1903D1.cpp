#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n;
long long ans = 0;

void solve() {
	scanf("%d", &n);
	string s;
	ans = 0;
	cin >> s;
	for (int i = 0; i < n; i++) {
		int one = 0;
		int sum = 0;
		for (int j = i; j < n; j++) {
			if (s[j] == '1' && one <= 0) {
				one = 3;
				sum++;
			}
			
			one--;
			
			ans += sum;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &t);
	
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}